<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Random Password Generator</title>
    <link rel="stylesheet" href="randompassword.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.4/css/all.min.css">

</head>
<body>
    <div class="password-container">
        <h2>Random Password Generator</h2>
        <div class="input-container">
            <input type="text" id="input" class="input" placeholder="cCreate a random password" readonly>
            <i class="far fa-copy fa-3x"></i>
        </div>
        <button class="btn">Generate</button>
    </div>
    <div class="alert-container active">testing</div>



    <script>
  let btn = document.querySelector(".btn")
let inputs = document.getElementById("input")

let copyPwd = document.querySelector(".fa-copy")

let alertText = document.querySelector(".alert-container")

copyPwd.addEventListener('click',()=>{
    copyPass()

    if(inputs.value){
        alertText.classList.remove("active")

        setTimeout(() => {
            alertText.classList.add("active")
    
        }, 2000);
    }

})

btn.addEventListener('click', ()=>{
    generatePAssword()
})

let generatePAssword = ()=>{
    const chars = "0123456789abcdefghijklmnopqrstuvwxtz!@#$%^&*()_+?:{}[]ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    const pwdLenght = 12

    let password = ""

    for (let index = 0; index < pwdLenght; index++) {
        const randomNum = Math.floor(Math.random() * chars.length)
        password += chars.substring(randomNum, randomNum +1)
        console.log(randomNum, password);
    }
    inputs.value = password
    alertText.innerText = `${password} has been copied `

}

let copyPass = () =>{
    inputs.select();
    navigator.clipboard.writeText(inputs.value)
}
  </script>
</body>
</html>
