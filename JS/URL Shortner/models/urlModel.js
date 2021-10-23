const mongoose = require('mongoose');

const shortUrlSchema = new mongoose.Schema({
   url: {
      type: String,
      required: true,
   },

   shortId: {
      type: String,
      required: true,
   },
});

const ShortURL = mongoose.model('ShortURL', shortUrlSchema);

module.exports = ShortURL;
