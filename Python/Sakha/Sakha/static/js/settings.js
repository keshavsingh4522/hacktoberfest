/*--------------------------------
* Functionality related with hiding flashed message
____________________________________*/
const msgContainer = document.querySelector('.message--container');
const msgHideBtn = document.querySelector('.message__hide__btn');

if(msgContainer) {
    
    msgHideBtn.addEventListener('click', () => {
        msgContainer.classList.add('message--hide');
    })
}



/*-------------------------------
 * Functionality related with sending json for names fields
---------------------------- */
const firstname = document.querySelector('.firstname__field');
const lastname = document.querySelector('.lastname__field');
const nameForm = document.querySelector('.nameForm');


nameForm.addEventListener('submit', e => {
    e.preventDefault();

    fetch('/updateName', {
        headers : {
            'Content-Type':'application/json'
        },
        method : 'POST',
        body : JSON.stringify({
            'firstname':firstname.value,
            'lastname':lastname.value
        })
    })
    .then(res => res.text()).then(res => res)
    .catch(res => console.log(res.text()))

    msgContainer.classList.remove('message--hide');
})



/*-------------------------------
 * Functionality related with sending json for about_user field
---------------------------- */
const aboutUser = document.querySelector('.about_user');
const address = document.querySelector('.address')
const aboutForm = document.querySelector('.aboutForm');

aboutForm.addEventListener('submit', e => {
    e.preventDefault();

    fetch('/updateAboutUser', {
        headers : {
            'Content-Type':'application/json'
        },
        method : 'POST',
        body : JSON.stringify( {
            'about_user':aboutUser.value,
            'address':address.value
        })
    })
    .then(res => res.text()).then(res => res)
    .catch(res => console.log(res.text()))

    msgContainer.classList.remove('message--hide');
})