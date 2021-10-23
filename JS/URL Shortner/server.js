const mongoose = require('mongoose');
const dotenv = require('dotenv');

// env configuration
dotenv.config({ path: './.env' });

const app = require('./app');

// DB variable
const DB = process.env.DATABASE.replace(
   '<PASSWORD>',
   process.env.DATABASE_PASSWORD
);

// DB Connection
mongoose
   .connect(DB, {
      useUnifiedTopology: true,
      useNewUrlParser: true,
   })
   .then(() => {
      console.log(`Database Connection Successful!`);
   })
   .catch((err) => {
      console.log(`Error Connecting...! The Error Is: ${err}`);
   });

// server PORT
const PORT = process.env.PORT || 3000;

// start server
app.listen(PORT, () => {
   console.log(`Server is running on PORT: ${PORT}`);
});
