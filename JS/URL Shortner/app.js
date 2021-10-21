// dependencies
const express = require('express');
const createHttpErrors = require('http-errors');
const path = require('path');
const urlRouter = require('./routes/urlRouter');

const ShortURL = require('./models/urlModel');

const app = express();

app.use(express.static(path.join(__dirname, 'public')));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

// view engine
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

// router
app.use('/', urlRouter);

app.use((req, res, next) => {
   next(createHttpErrors.NotFound());
});

app.use((err, req, res, next) => {
   res.status(err.status || 500).render('index', { error: err.message });
});

module.exports = app;
