/*------------------------------
Follow button related functionality
---------------------------------*/
const followBtn = document.querySelector('.follow__btn');
const followersBtn = document.querySelector('.followers__btn');


if(followBtn) {

    followBtn.addEventListener('click',function(e) {
        e.preventDefault();
    
        fetch('/follow_action', {
            headers : {
                'Content-Type' : 'application/json'
            },
            method : 'POST',
            body : JSON.stringify( {
                'user_id': Number(this.dataset.userid)
            })
        })
        .then(res => res.json()).then(res =>{
            this.textContent = (res['follow'] ? res['follow'] : res['unfollow']);
            followersBtn.textContent = `${res['followers']} followers`;
        })
    });
}




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