const express = require('express');
const {
   getHomePage,
   createShortUrl,
   browseShortenUrl,
} = require('./../controllers/urlController');

const router = express.Router();

router.route('/').get(getHomePage).post(createShortUrl);

router.get('/:shortId', browseShortenUrl);

module.exports = router;
