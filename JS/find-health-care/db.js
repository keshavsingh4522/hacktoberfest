import mongoose from 'mongoose';
import config from './config.js';

export default () => {
  mongoose
    .connect(config.mongodb_uri, {
      useNewUrlParser: true,
      useUnifiedTopology: true,
    })
    .then(() => console.log('database connected'))
    .catch((err) => console.log(err));
};
