const http = require("http");
const express = require("express");
const socketio = require("socket.io");
const formatMessage = require("./utils/messages");
const {userJoin, getCurrentUser, userLeave, getRoomUsers} = require("./utils/users");

const app = express();
const server = http.createServer(app);
const io = socketio(server);

const PORT = 80 || process.env.PORT;

app.use(express.static("public"))

const botName = "ChatWiz";

//* Run when client connects
io.on("connection", function(socket){

    socket.on("joinRoom", function({username, room}){

        const user = userJoin(socket.id, username, room);

        socket.join(user.room);

        //* Welcome current user
        socket.emit("message", formatMessage(botName, "Welcome to ChatWiz!!!"));
    
        //* Broadcast when a user connects
        socket.broadcast.to(user.room).emit("message", formatMessage(botName, `${user.username} just joined the chat`));

        //* Send users and room info
        io.to(user.room).emit("roomUsers", {
            room: user.room,
            users: getRoomUsers(user.room)
        });

    });

    console.log("new WS connects.....");
    
    //* Listen to chat message
    socket.on("chatMessage", (msg) => {
        const user =  getCurrentUser(socket.id);
        io.to(user.room).emit("message", formatMessage(user.username, msg));
    })

    //* Runs when a user disconnects
    socket.on("disconnect", ()=>{
        const user =  userLeave(socket.id);
        if(user){
            io.to(user.room).emit("message", formatMessage(botName, `${user.username} left the chat`));

            //* Send users and room info
            io.to(user.room).emit("roomUsers", {
                room: user.room,
                users: getRoomUsers(user.room)
            });
        }
    });

});

server.listen(PORT, function(){
    console.log(`server is running on port ${PORT}`);
});