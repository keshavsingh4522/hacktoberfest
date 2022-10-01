import express from 'express';
import config from './config.js';
import db from './db.js';
import route from './route.js';
import cors from 'cors';

const app = express();

app.use(express.json());
app.use(cors());
app.use(express.urlencoded({ extended: true }));
app.use('/api', route);
app.use('*', (req, res) => {
  res.status(404).json({
    message: 'route does not exist',
  });
});

db();
app.listen(config.port, () => {
  console.log('app started');
});
