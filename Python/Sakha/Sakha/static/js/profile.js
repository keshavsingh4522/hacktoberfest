/*---------------------------------
Functionality related with hiding or showing the profile navigation
----------------------------------*/ 
const profileBtn = document.querySelector('.profile__btn');
const profileNavigation = document.querySelector('.profile__navigation');

profileBtn.addEventListener('click', () => {
    profileNavigation.classList.toggle('profile__navigation__hidden');
});




/*----------------------------------
* Functionality for showing and hiding the post side navigation
-----------------------------------*/
const sideNavShowBtns = document.querySelectorAll('.sideNavShowBtn');
const sideNavHideBtns = document.querySelectorAll('.sideNavHideBtn');
const sideNavs = document.querySelectorAll('.post__related__btn__links');

sideNavShowBtns.forEach((btn, index) => {
        btn.addEventListener('click',() => {
        sideNavs[index].classList.add('show__post__sidenav');
    });
});

sideNavHideBtns.forEach((btn, index) => {
        btn.addEventListener('click',() => {
        sideNavs[index].classList.remove('show__post__sidenav');
    });
});



/*-----------------------------------
 * Heart button related functionality
 ------------------------------------*/
 const heartBtns = document.querySelectorAll('.heart__btn');
 const totalHearts = document.querySelectorAll('.heart__btn span');
 const heartIcons = document.querySelectorAll('.heart__btn i');
 
 if (heartBtns) {
     
     heartBtns.forEach((heartBtn, index) => {
         heartBtn.addEventListener('click', e => {
             e.preventDefault();
             const postId = Number(heartBtn.dataset.postid);
     
             fetch('/like_action', {
                 headers : {
                     'Content-Type':'application/json'
                 },
                 method : 'POST',
                 body : JSON.stringify({
                     'post_id':postId
                 })
             })
             .then(res => res.json()).then(res => {
                 heartBtn.classList.toggle('heart__btn__active');
                 totalHearts[index].textContent = res["totalLikes"];
                 heartIcons[index].classList.toggle('far');
                 heartIcons[index].classList.toggle('fas');
             })
         })
     })
 }
 