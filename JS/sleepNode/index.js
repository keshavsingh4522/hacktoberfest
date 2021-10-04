const express = require('express');
const app = express();
const axios = require('axios');

const PORT = 3000 || process.env.PORT

app.get('/', (req,res)=>{
    res.send('Welcome')
    setInterval(() => {
        axios.get('https://your-url-here.com/')
    .then(()=>{
        console.log('pinged')
    })
    .catch(err => console.log(err))
    }, 600000);
})

app.listen(PORT, console.log(`Server listening on ${PORT}`));