const navLinks = document.querySelector('.nav-links');
const hamburgerBtn = document.querySelector('.hamburger-btn');
const toggleImg = document.querySelector('#toggle-img');

hamburgerBtn.addEventListener('click', () => {
 navLinks.classList.toggle('open');
 isOpen = navLinks.classList.contains('open');
 if (isOpen) {
    toggleImg.src = './img/icon-close.svg';
 } else {
    toggleImg.src = './img/icon-hamburger.svg';
 }
})

