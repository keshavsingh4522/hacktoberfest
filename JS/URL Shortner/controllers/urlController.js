// dependencies
const shortId = require('shortid');
const createHttpErrors = require('http-errors');
const ShortURL = require('./../models/urlModel');

exports.getHomePage = async (req, res) => {
   res.status(200).render('index');
};

exports.createShortUrl = async (req, res, next) => {
   try {
      const { url } = req.body;

      if (!url) {
         throw createHttpErrors.BadRequest('Provide a valid URL!');
      }

      const urlExists = await ShortURL.findOne({ url });
      // console.log(urlExists.shortId);

      if (urlExists) {
         res.render('index', {
            short_url: `${req.hostname}/${urlExists.shortId}`,
         });
         return;
      }

      const shortUrl = new ShortURL({ url: url, shortId: shortId.generate() });
      const result = await shortUrl.save();

      res.render('index', {
         short_url: `${req.hostname}/${result.shortId}`,
      });
   } catch (err) {
      next(err);
   }
};

exports.browseShortenUrl = async (req, res, next) => {
   try {
      const { shortId } = req.params;
      const result = await ShortURL.findOne({ shortId });

      if (!result) {
         throw createHttpErrors('ShortId does not exist!');
      }

      res.redirect(result.url);
   } catch (err) {
      next(err);
   }
};
