import "../Styles/accomo.css";
import React, { useEffect } from "react";

import l11 from "../assets/eventmanagement1.jpeg";
import l21 from "../assets/eventmanagement2.jpeg";
import l31 from "../assets/eventmanagement3.jpeg";
import l41 from "../assets/eventmanagement4.jpeg";

import "../Styles/navbar.css";

import acc11 from "../assets/Heroimage1.jpg";
import acc21 from "../assets/Heroimage3.jpg";
import acc31 from "../assets/Heroimage3.jpg";

import cul11 from "../assets/food1.jpg";
import cul21 from "../assets/food2.jpg";
import cul31 from "../assets/food4.jpg";

import lux2 from "../assets/maam.avif";
import Container from "react-bootstrap/Container";
import Row from "react-bootstrap/Row";
import Col from "react-bootstrap/Col";
import Carousel from "react-bootstrap/Carousel";
import AOS from "aos";
import "aos/dist/aos.css";
import NearByPlaces from "./NearByPlaces";
function Accomodation(props) {
  useEffect(() => {
    const shouldEnableAOS = window.innerWidth >= 768;

    if (shouldEnableAOS) {
    AOS.init({
      // Configuration OPTIONS
      duration: 800, // Duration of animation
      once: true, // Only animate once
      mirror: false, // Animate elements in different directions
    });
  }
  }, []);
  return (
    <>
      <Row className="boot-row">
        <Col span={14} className="coro-col2">
          <h1>EVENTS & WEDDING</h1>

          <Carousel
            fade
            data-aos="fade"
            data-aos-offset="200"
            data-aos-delay="200"
            data-aos-duration="500"
          >
            <Carousel.Item id="slider-images2">
              <img
                id="slider-images2"
                className="d-block w-100"
                src={l11}
                alt="Second slide"
                style={{ height: "30rem", width: "100rem" }}
              />
            </Carousel.Item>
            <Carousel.Item id="slider-images2">
              <img
                id="slider-images2"
                className="d-block w-100"
                src={l21}
                alt="Third slide"
                style={{ height: "30rem", width: "100rem" }}
              />
            </Carousel.Item>
            <Carousel.Item id="slider-images2">
              <img
                className="d-block w-100"
                src={l31}
                id="slider-images2"
                alt="Third slide"
                style={{ height: "30rem", width: "100rem" }}
              />
            </Carousel.Item>
            <Carousel.Item id="slider-images2">
              <img
                className="d-block w-100"
                id="slider-images2"
                src={l41}
                alt="First slide"
                style={{ height: "30rem", width: "100rem" }}
              />
            </Carousel.Item>
          </Carousel>
        </Col>
      </Row>

      <Container fluid style={{ padding: 0, right: 0 }}>
        <Row className="parentLux" style={{ padding: 0 }}>
          <Col
            data-aos="fade-left"
            data-aos-offset="200"
            data-aos-delay="200"
            data-aos-duration="500"
            lg={6}
            style={{ padding: 0 }}
          >
            <Carousel fade id="luxImg">
              <Carousel.Item>
                <img
                  className="d-block w-100"
                  src={acc11}
                  id="luxImgss"
                  alt="First slide"
                />
              </Carousel.Item>
              <Carousel.Item>
                <img
                  className="d-block w-100"
                  src={acc21}
                  id="luxImgss"
                  alt="Second slide"
                />
              </Carousel.Item>
              <Carousel.Item id="luxImgss">
                <img
                  className="d-block w-100"
                  src={acc31}
                  id="luxImgss"
                  alt="Third slide"
                />
              </Carousel.Item>
            </Carousel>
          </Col>
          <Col
            lg={6}
            className="luxDiv"
            data-aos="fade-right"
            data-aos-offset="200"
            data-aos-delay="200"
            data-aos-duration="500"
          >
            <div>
              <h4 style={{ color: "#debe64", fontWeight: "600" }}>
                LUXURY ACCOMMODATION
              </h4>
              <p>
                At SIRI Ambari, we go above and beyond to ensure your stay is
                nothing short of extraordinary. Our dedicated staff is committed
                to providing personalized service and attention to detail,
                making your experience truly unforgettable. Come, escape to the
                enchanting land of Coorg and let SIRI Ambari be your gateway to
                an extraordinary journey. Book your stay with us today and
                discover the allure of this paradise on earth.
              </p>
              <p>
                Our hotel is designed to cater to all your needs, whether you
                are here for a romantic getaway or a family vacation. With its
                stunning architecture and scenic surroundings, our hotel is the
                perfect place to escape the hustle and bustle of everyday life.
                From the moment you step into our hotel, you will be greeted
                with warm hospitality and a sense of relaxation. Our rooms are
                spacious and comfortable, providing you with the perfect space
                to unwind after a long day of exploring the stunning natural
                beauty of Coorg.
              </p>
              <p>
                Our hotel is equipped with all the modern amenities you need to
                make your stay comfortable and enjoyable. Whether you want to
                take a dip in our pool, work out in our state-of-the-art fitness
                center, or indulge in some of the finest cuisine in Coorg at our
                restaurant, we have everything you need to make your stay
                unforgettable. Coorg is known for its breathtaking natural
                beauty, and our hotel is the perfect place to explore it from.
                Whether you want to go on a guided tour of the local wildlife,
                take a hike through the stunning hills, or simply sit back and
                enjoy the stunning views, our hotel is the perfect starting
                point for all your adventures.
              </p>
              <p style={{ color: "#debe64", textAlign: "center" }}>
                <i>
                  At our hotel, we pride ourselves on offering you an
                  unforgettable experience that will stay with you for years to
                  come. Whether you are looking for a romantic getaway, a family
                  vacation, or simply a place to escape the hustle and bustle of
                  everyday life, our hotel is the perfect choice for you. Book
                  your stay with us today and discover the magic of Coorg for
                  yourself.
                </i>
              </p>

              <button className="buttonLux">BOOK NOW</button>
              {/* <button className="buttonLux">VIEW ACCOMODATION OPTIONS</button> */}
            </div>
          </Col>
        </Row>
      </Container>

      <div
        className="parentLux2"
        data-aos="fade-in"
        data-aos-offset="200"
        data-aos-delay="100"
        data-aos-duration="500"
      >
        <div className="luxDiv2">
          <h4 style={{ color: "#debe64", fontWeight: "600" }}>
            SIRI - MULTI CUISINE SPECIALITY RESTAURANTE
          </h4>

          <p style={{ color: "#363433", fontWeight: "500" }}>
            At Siri Ambari, we take pride in offering an extensive menu of Coorg
            traditional, non-veg, veg, coastal dishes, and Chinese menu items
            that are sure to please every palate. Come dine with us and
            experience the best of local and international cuisine in a warm and
            welcoming atmosphere.
          </p>
          <p style={{ color: "#363433", fontWeight: "500" }}>
            From 6 AM to 11 PM.
          </p>
          {/* <button className="buttonLux">VIEW OTHERF OPTIONS</button> */}
        </div>
        <img
          alt="age3"
          id="luxImg22"
          src={lux2}
          style={{ boxShadow: "rgba(0, 0, 0, 0.35) 0px 5px 15px" }}
        />
      </div>
      <Container fluid style={{ padding: 0, right: 0, marginBottom: "6rem" }}>
        <Row className="parentLux" style={{ padding: 0 }}>
          <Col
            lg={6}
            style={{ padding: 0 }}
            data-aos="fade-left"
            data-aos-offset="200"
            data-aos-delay="200"
            data-aos-duration="500"
          >
            {" "}
            <Carousel fade id="luxImg21">
              <Carousel.Item>
                <img
                  className="d-block w-100"
                  id="luxImgss2"
                  src={cul21}
                  alt="First slide"
                />
              </Carousel.Item>
              <Carousel.Item>
                <img
                  className="d-block w-100"
                  id="luxImgss2"
                  src={cul11}
                  alt="Second slide"
                />
              </Carousel.Item>
              <Carousel.Item id="luxImg">
                <img
                  className="d-block w-100"
                  id="luxImgss2"
                  src={cul31}
                  alt="Third slide"
                />
              </Carousel.Item>
            </Carousel>
          </Col>
          <Col
            lg={6}
            id="luxDiv2"
            data-aos="fade-right"
            data-aos-offset="200"
            data-aos-delay="200"
            data-aos-duration="500"
            className="luxDiv"
          >
            {" "}
            <div>
              <h4 style={{ color: "#debe64", fontWeight: "600" }}>
                Experience a culinary delight with our delectable dishes, made
                to perfection.
              </h4>
              <h5 style={{ color: "#debe64", fontWeight: "500" }}>
                Coorg Traditional Dishes:
              </h5>
              <ul>
                <li>
                  Indulge in the authentic flavors of Coorg with our traditional
                  dishes such as Pandi Curry, Bamboo Shoot Curry, Kadambuttu,
                  Nool Puttu, and more.
                </li>
                <li>
                  Experience the rich and spicy taste of our signature
                  Coorgi-style Biryani made with locally sourced ingredients.
                </li>
                <li>
                  Try our Coorgi-style pork dishes, made with tender pork
                  marinated in a blend of Coorgi spices and cooked to
                  perfection.
                </li>
              </ul>

              <h5 style={{ color: "#debe64", fontWeight: "500" }}>
                Non-Veg Dishes:
              </h5>
              <ul>
                <li>
                  Satisfy your cravings for meat with our range of non-veg
                  dishes, including Chicken Chettinad, Mutton Rogan Josh, Fish
                  Fry, and Prawns Masala.
                </li>
                <li>
                  Sink your teeth into our succulent Tandoori Chicken, marinated
                  in a spicy blend of yogurt and Indian spices and cooked in a
                  traditional clay oven.
                </li>
                <li>
                  Sample our delectable Chicken 65, a spicy and crispy fried
                  chicken dish that is sure to please your taste buds.
                </li>
              </ul>
              <h5 style={{ color: "#debe64", fontWeight: "500" }}>
                Veg Dishes:
              </h5>
              <ul>
                <li>
                  Our vegetarian menu is equally enticing, with dishes such as
                  Paneer Tikka Masala, Chana Masala, Baingan Bharta, and Aloo
                  Gobi.
                </li>
                <li>
                  Try our delicious Vegetable Biryani, a fragrant and flavorful
                  rice dish made with an assortment of fresh veggies and
                  aromatic spices.
                </li>
                <li>
                  Don't miss our crispy and spicy Gobi Manchurian, a popular
                  Indo-Chinese dish made with cauliflower florets fried and
                  coated in a tangy sauce.
                </li>
              </ul>
              <h5 style={{ color: "#debe64", fontWeight: "500" }}>
                Coastal Dishes:
              </h5>
              <ul>
                <li>
                  Treat yourself to the fresh and flavorful seafood from the
                  coastal region, such as Fish Curry, Prawns Fry, Crab Masala,
                  and Squid Roast.
                </li>
                <li>
                  Sample our famous Mangalorean-style Chicken Sukka, a spicy and
                  tangy chicken dish that is a must-try for meat lovers.
                </li>
                <li>
                  Experience the unique blend of Indian and Chinese flavors with
                  our Indo-Chinese dishes, such as Chilli Chicken, Hakka
                  Noodles, and Szechuan Fried Rice.
                </li>
              </ul>
              <h5 style={{ color: "#debe64", fontWeight: "500" }}>
                Chinese Dishes:
              </h5>
              <ul>
                <li>
                  Indulge in the comforting and satisfying flavors of our
                  Chinese menu, including classics such as Sweet and Sour
                  Chicken, Kung Pao Shrimp, and Vegetable Chow Mein.
                </li>
                <li>
                  Try our spicy and flavorful Szechuan dishes, such as Szechuan
                  Chicken, Szechuan Fish, and Szechuan Tofu.
                </li>
                <li>
                  Don't miss our signature Chinese-style Fried Rice and Noodles,
                  made with fresh veggies and your choice of meat or tofu.
                </li>
              </ul>

              <button className="buttonLux">BOOK NOW</button>
              {/* <button className="buttonLux">VIEW ACCOMODATION OPTIONS</button> */}
            </div>
          </Col>
        </Row>
      </Container>
      <NearByPlaces />
    </>
  );
}
export default Accomodation;
