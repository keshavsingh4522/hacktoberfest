const bars = document.querySelector(".menu-bar");
const barsMenu = document.querySelector("ul");
const dropDown = document.querySelectorAll(".drop");
console.log(dropDown);
bars.addEventListener("click", () => {
  barsMenu.classList.toggle("active");
});
dropDown.forEach((item) => {
  item.addEventListener("click", () => {
    item.classList.toggle("active");
    item.lastElementChild.classList.toggle("active");
  });
});

// dropDown.forEach((item) => {
//   item.addEventListener("click", () => {
//     item.classList.toggle("active");
//   });
// });
