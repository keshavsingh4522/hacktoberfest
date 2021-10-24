const coinBaseURL = "https://api.coinbase.com/v2/prices/spot?currency=USD";
const graphContainer = document.getElementById("graph-container");
const chart = LightweightCharts.createChart(graphContainer, {
  height: 750,
});

chart.applyOptions({
  layout: {
    background: {
      type: LightweightCharts.ColorType.Solid,
      color: "#E4D8DC",
    },
    textColor: "#696969",
    fontSize: 12,
    fontFamily: "Calibri",
  },
});

const lineSeries = chart.addLineSeries();

let displayData = [];

setInterval(() => {
  var xmlHttp = new XMLHttpRequest();
  xmlHttp.open("GET", coinBaseURL, false);
  xmlHttp.send(null);

  const response = JSON.parse(xmlHttp.responseText);
  if (response != null) {
    const d = new Date();
    displayData.push({ time: d.getTime(), value: response.data.amount })
    lineSeries.setData(displayData);
  }
}, 1000*60);