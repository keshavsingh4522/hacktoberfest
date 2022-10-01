import Model from './model.js';
import express from 'express';
import { check, validationResult } from 'express-validator';
import { toLatLon, headingDistanceTo, insidePolygon } from 'geolocation-utils';

const router = express.Router();

router.post(
  '/',
  [check('lon').not().isEmpty(), check('lat').not().isEmpty()],

  async (req, res) => {
    let lat = req.body.lat;
    let lon = req.body.lon;
    const errors = validationResult(req);
    if (!errors.isEmpty()) {
      return res.status(400).json({ errors: errors.array() });
    }
    let polygon = [
      [6.092243006, 9.000640869],
      [8.818318429, 9.000640869],
      [8.818318429, 11.523989174],
      [6.092243006, 11.523989174],
      [6.092243006, 9.000640869],
    ]; // polygon of kaduna state

    if (insidePolygon([parseFloat(lon), parseFloat(lat)], polygon) == false) {
      res.status(400).json({
        success: false,
        message: 'location is not inside of kaduna',
      });
    }
    let data = [];
    const location = toLatLon([parseFloat(lon), parseFloat(lat)]);

    try {
      let doc = await Model.find({});
      doc.map((item) => {
        let itemObj = item.toObject();
        let loc = toLatLon([
          parseFloat(itemObj.longitude),
          parseFloat(itemObj.latitude),
        ]);
        //console.log(loc);
        let dist = headingDistanceTo(location, loc);
        data.push({ distance: dist.distance, doc: itemObj });
      });
      data.sort((a, b) => a.distance - b.distance);
      let file = data.slice(0, 5);
      res.status(200).json({
        success: true,
        file,
      });
    } catch (error) {
      res.status(500).json({
        success: false,
        message: error.message,
      });
    }
  }
);

export default router;
