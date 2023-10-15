var backdrop = document.querySelector(".backdrop");
var modal = document.querySelector(".modal");
var modalNoButton = document.querySelector(".modal__action--negative");
var selectPlanButtons = document.querySelectorAll(".plan button");
var toggleButton = document.querySelector(".toggle-button");
var mabileNav = document.querySelector(".mobile-nav");

for (var i = 0; i < selectPlanButtons.length; i++) {
  selectPlanButtons[i].addEventListener("click", function () {
    // modal.style.display = "block";
    // backdrop.style.display = "block";
    // modal.className = 'open'; this will actually overwitem
    modal.classList.add("open");
    backdrop.classList.add("open");
  });
}

backdrop.addEventListener("click", function () {
  // mabileNav.style.display = "none";
  mabileNav.classList.remove("open");

  closeModal();
});

if (modalNoButton) {
  modalNoButton.addEventListener("click", closeModal);
}

function closeModal() {
  // backdrop.style.display = "none";
  // modal.style.display = "none";

  if (modal) {
    modal.classList.remove("open");
  }

  backdrop.classList.remove("open");
}

toggleButton.addEventListener("click", function () {
  // mabileNav.style.display = "block";
  // backdrop.style.display = "block";
  mabileNav.classList.add("open");
  backdrop.classList.add("open");
});
