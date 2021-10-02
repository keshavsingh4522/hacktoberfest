const toggleDarkMode = document.querySelector(".toggler");
const toggleText = document.querySelector(".toggle-txt");

let darkMode = localStorage.getItem("darkMode");


//This will trigger the dark mode when clicked
const enableDarkMode = () => {
  document.body.classList.add("modedark");
  toggleText.textContent = "Light";
  localStorage.setItem("darkMode", "enabled");
};

//This will triggered when the user returns to Light Mode
const disableDarkMode = () => {
  document.body.classList.remove("modedark");
  toggleText.textContent = "Dark";
  localStorage.setItem("darkMode", null);
};

// This will save the state of the Mode 
if (darkMode == "enabled") {
  enableDarkMode();
}


// This is triggered when the Dark mode box is cliked

toggleDarkMode.addEventListener("click", () => {
  let darkMode = localStorage.getItem("darkMode");

  if (darkMode !== "enabled") {
    enableDarkMode();
  } else {
    disableDarkMode();
  }


});
