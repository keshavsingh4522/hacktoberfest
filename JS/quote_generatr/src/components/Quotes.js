import React, { useState, useEffect } from "react";
import randomColor from "randomcolor";
import { FaTwitterSquare, FaQuoteLeft } from "react-icons/fa";
const axios = require("axios");

const Quotes = () => {
  const [bgcolor, setBgColor] = useState("");
  const [quote, setQuote] = useState([]);
  const [author, setAuthor] = useState([]);
  const min = 1;
  const max = 1644;

  function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min) + min);
  }

  function getQuotes() {
    axios
      .get("https://type.fit/api/quotes/")
      .then((res) => {
        console.log(res);
        const allquotes = res.data;
        const id = getRandomInt(min, max);
        setQuote(allquotes[id].text);
        setAuthor(allquotes[id].author);
      })
      .catch((error) => console.error(error));
    const clr = randomColor();
    setBgColor(clr);
    document.body.style.backgroundColor = clr;
  }

  useEffect(() => {
    getQuotes();
  }, []);

  const handelClick = () => {
    getQuotes();
  };

  return (
    <div id="quotes-box">
      <div id="text" style={{ color: bgcolor }}>
        <FaQuoteLeft /> {quote}
      </div>
      <div id="author" style={{ color: bgcolor }}>
        -{author}
      </div>
      <div id="tweetbtn">
        <a
          type="button"
          role="button"
          title="Share on twitter"
          href={`https://twitter.com/intent/tweet?text=${quote} - ${author}`}
          rel="noopener"
          id="tweet-quote"
        >
          {" "}
          <FaTwitterSquare id="icon" style={{ fill: bgcolor }} />
        </a>

        <div id="new-quote">
          <button
            id="button"
            style={{ backgroundColor: bgcolor }}
            onClick={handelClick}
          >
            New Quotes
          </button>
        </div>
      </div>
    </div>
  );
};

export default Quotes;
