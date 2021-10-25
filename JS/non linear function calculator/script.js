let inputA = document.getElementById('a')
let inputB = document.getElementById('b')
let inputC = document.getElementById('c')
let aView = document.getElementById('a-view')
let aPangkatView = document.getElementById('a-pangkat-view')
let aPangkatInput = document.getElementById('pangkat-a')
let bView = document.getElementById('b-view')
let bPangkatView = document.getElementById('b-pangkat-view')
let bPangkatInput = document.getElementById('pangkat-b')
let cView = document.getElementById('c-view')
let cPangkatView = document.getElementById('c-pangkat-view')
let firstOperator = document.getElementById('operator-1-view')
let secondOperator = document.getElementById('operator-2-view')
let draggables = document.querySelectorAll(".input-container")
let containers = document.querySelectorAll(".dropzone")
let operator1 = document.getElementById('operator-1-view')
let operator2 = document.getElementById('operator-2-view')
let operatorInput1 = document.getElementById("lambang-1")
let operatorInput2 = document.getElementById("lambang-2")
let template1Input = document.getElementById("template-1")
let template2Input = document.getElementById("template-2")
let dropZoneContainer = document.querySelector(".dropzone-container")
let titleContainer = document.querySelector("#title")
let viewPosisi1 = document.getElementById("posisi-1") 
let viewPosisi2 = document.getElementById("posisi-2") 
let viewPosisi3 = document.getElementById("posisi-3") 
let viewAContainer = document.getElementById("a-view-container") 
let viewBContainer = document.getElementById("b-view-container") 
let viewCContainer = document.getElementById("c-view-container") 
let inputContainerdropzone1 = document.querySelector("#input-a") 
let inputContainerdropzone2 = document.querySelector("#input-b") 
let persamaan = ["a","b"]
let a = 1,apangkat = 2,aoperator = "+",b = "e" ,bpangkat = 1,boperator = "+",c=4   
let buttonProcess = document.getElementById("process-id")
let result = 0
let batasBawahElement = document.getElementById("x-value")
let batasAtasElement = document.getElementById("y-value")
let epsilonElement = document.getElementById("e-value")
let container = document.querySelector(".container")
let hasilXAhkir = 0.0
let modeElement = document.getElementById("mode")
let batasAtas,batasBawah,epsilon,mode

draggables.forEach(e => {
    e.addEventListener("dragstart",() => {
        e.classList.add("dragging")
    })

    e.addEventListener("dragend",() => {
        e.classList.remove("dragging")
    })    
});

modeElement.addEventListener("input", (e) => {
    mode = e.target.value

    if(mode == "mode-2") {

        document.getElementById("x-value-label").innerText = "first Guess"
        document.getElementById("y-value-label").innerText = "Second Guess"
    } else {
        
        document.getElementById("x-value-label").innerText = "First Guess"
        document.getElementById("y-value-label").innerText = "Seconf Guess"
    }
})


containers.forEach(container => {
    container.addEventListener("dragover", (e) => {
        e.preventDefault()
        // console.log(e.target.id)
        const draggable = document.querySelector(".dragging")
        if (checkParent(container,e.target)){
            if (container.id == "dropzone-1" && e.target.id == "input-b") {
                
                // viewPosremoveChild
                // console.log(viewPosisi1.childNodes.length);
                viewPosisi1.appendChild(viewBContainer)
                persamaan.reverse()   
                console.log(persamaan);
                
            }
            else if(container.id == "dropzone-1" && e.target.id == "input-a") {
                
                viewPosisi1.appendChild(viewAContainer)
                persamaan.reverse()
                console.log(persamaan);
            }
            
            else if (container.id == "dropzone-2" && e.target.id == "input-a") {
                
                viewPosisi2.appendChild(viewAContainer)
                persamaan = ["a","b"]
                console.log(persamaan);
            }
            
            else if (container.id == "dropzone-2" && e.target.id == "input-b") {
                
                viewPosisi2.appendChild(viewBContainer)
                persamaan = ["a","b"]
                console.log(persamaan);
            }
        }
        container.appendChild(draggable)
    })
})

function checkParent(parent, child) {
    if (parent.contains(child)){

        return true;
    }

    return false;
}

inputA.addEventListener('input',(e) => {
    inputValue = e.target.value
    aView.innerText =  inputValue
})

inputB.addEventListener('input',(e) => {
    inputValue = e.target.value
    bView.innerText =  inputValue
})

inputC.addEventListener('input',(e) => {
    inputValue = e.target.value
    cView.innerText =  inputValue
})


aPangkatInput.addEventListener('input',(e) => {
    inputValue = e.target.value
    aPangkatView.innerText =  inputValue
})

bPangkatInput.addEventListener('input',(e) => {
    inputValue = e.target.value
    bPangkatView.innerText =  inputValue
})

operatorInput1.addEventListener('input',(e) => {
    inputValue = e.target.value
    operator1.innerText =  inputValue
})

operatorInput2.addEventListener('input',(e) => {
    inputValue = e.target.value
    operator2.innerText =  inputValue
})



buttonProcess.addEventListener("click",() => {
    batasAtas = parseFloat(batasAtasElement.value)
    batasBawah = parseFloat(batasBawahElement.value)
    epsilon = parseFloat(epsilonElement.value)
    
    // persamaan construction
    
    // a
    a = parseFloat(aView.textContent)
    if (isNaN(a)) {
        a = aView.textContent
        
        if(a == "e") {
            a = 2.71828183
        }
    }
    
    // a pangkat
    apangkat = parseInt(aPangkatView.textContent)
    if (isNaN(apangkat)) {
        apangkat = aPangkatView.textContent
        if (apangkat == "e"){
            apangkat = 2.71828183
        }
    }
    // a operator
    aoperator = firstOperator.textContent


    
    
    // b
    b = parseFloat(bView.textContent)
    if (isNaN(b)) {
        b = bView.textContent
        
        if(b == "e") {
            b = 2.71828183
            console.log(b)
        }
        
    }
    // b pangkat
    bpangkat = parseInt(bPangkatView.textContent)
    
    
    if (isNaN(bpangkat)) {
        bpangkat = bPangkatView.textContent
        
        if(bpangkat == "e") {
            b = 2.71828183
        }
    }
    // b operator
    boperator = secondOperator.textContent
    
    // c
    c = parseFloat(cView.textContent)
    
    if ( mode == "mode-1") {

        falsePosition(batasBawah,batasAtas,epsilon)
    } else {
        secant(batasBawah,batasAtas,epsilon,10)
    }
    // f(12)

})

function f(x){

    let aVal = a
    let bVal = b
    let cVal = c

    let aoperatorVal = aoperator
    let boperatorVal = boperator

    let bpangkatVal = bpangkat
    let apangkatVal = apangkat
     
    if (persamaan[0] == 'a'){
        if(aoperatorVal == "+"){
            console.log("masuk a +");
            if (apangkatVal=="x") {
                apangkatVal = x
            }
            if (boperatorVal == "+") {
                if (bpangkatVal=="x") {
                    bpangkatVal = x
                }
                console.log(aVal*x**apangkatVal,bVal**bpangkatVal,cVal);
                return aVal*x**apangkatVal + bVal**bpangkatVal+cVal
            }
            else if (boperatorVal == "-") {
                if (bpangkatVal=="x") {
                    bpangkatVal = x
                }

                console.log(aVal*x**apangkatVal,bVal**bpangkatVal,cVal);
                return aVal*x**apangkatVal + bVal**bpangkatVal-cVal
            }
        }
        
        if(aoperatorVal == "-"){
            console.log("masuk a -");
            // console.log("masuk -");
            if (apangkatVal=="x") {
                apangkatVal = x
            }
            if (aVal=="x") {
                aVal = x
            }
            if (boperatorVal == "+") {
                
                if (bpangkatVal=="x") {
                    bpangkatVal = x
                }
                
                if (bVal=="x") {
                    bVal = x
                }
                console.log(aVal*x**apangkatVal,bVal**bpangkatVal,bpangkatVal,cVal);
                return aVal*x**apangkatVal - bVal**bpangkatVal+cVal
            }
            else if (boperatorVal == "-") {
                if (bpangkatVal=="x") {
                    bpangkatVal = x
                }
                if (bVal == "x") {
                    bVal = x
                }
                console.log(aVal*x**apangkatVal,bVal**bpangkatVal,cVal);
                return aVal*x**apangkatVal - bVal**bpangkatVal-cVal
            }
        }
    }
    else if (persamaan[0] == 'b'){
        if(boperatorVal == "+"){
            console.log("masuk b +");
            if (bpangkatVal=="x") {
                bpangkatVal = x
            }
            if (bVal == "x") {
                bVal = x
            }
            if (aoperatorVal == "+") {
                if (apangkatVal=="x") {
                    apangkatVal = x
                }
                console.log(aVal*x**apangkatVal,bVal**bpangkatVal,cVal);
                return bVal**bpangkatVal + aVal*x**apangkatVal+cVal
            }
            else if (aoperatorVal == "-") {
                if (apangkatVal=="x") {
                    apangkatVal = x
                }
                console.log(aVal*x**apangkatVal,bVal**bpangkatVal,cVal);
                return bVal**bpangkatVal + aVal*x**apangkatVal-cVal
            }
        }
        
        if(boperator == "-")    {
            console.log("masuk b -");
            if (bpangkatVal=="x") {
                bpangkatVal = x
            }
            if (bVal=="x") {
                bVal = x
            }
            if (aoperatorVal == "+") {
                if (apangkatVal=="x") {
                    apangkatVal = x
                }
                console.log(aVal*x**apangkatVal,bVal**bpangkatVal,cVal);
                return bVal**bpangkatVal-aVal*x**apangkatVal+cVal
            }
            else if (aoperatorVal == "-") {
                if (apangkatVal== "x") {
                    apangkatVal = x
                }
                console.log(aVal*x**apangkatVal,bVal**bpangkatVal,cVal);
                return bVal**bpangkatVal - aVal*x**apangkatVal-cVal
            }
        }
    }
}


function falsePosition(x0,x1,e) {
    let step=0,x2=0.0

    step = 1
    x0 = parseFloat(x0)
    x1 = parseFloat(x1)
    e  = parseFloat(e)
    console.log ("\n\n FALSE Position Method Implementation \n\n")
    
    let condition = true
    while(condition){
        x2 = x0-(x1-x0) * f(x0)/(f(x1) - f(x0))

        // console.log(typeof(x0),typeof(x1));
        console.log("f(x0) = " +f(x0) +" x0 = "+ x0+ " f(x1) = "+f(x1)+" x1= " + x1 )
        console.log("iteration-"+ step +", x2="+x2+"and f(x2) = "+f(x2))
        
        let div = document.createElement("div")
        div.classList.add("step-result-container")
        div.setAttribute("id",`step-${step}`)
        div.innerHTML = `<div class="step-result">Langkah ke-${step} x = ${x2} , f(x) = ${f(x2)} </div>`
 
        container.appendChild(div)
        if(f(x0) * f(x2) < 0) {
            x1 = x2
        }
        else{
            x0=x2
        }
        
        step = step + 1
        condition = Math.abs(f(x2)) > e
        
        let div_2 = document.createElement("div")
        div_2.classList.add("step-result")
        div_2.innerHTML = `<b>X </b> : ${x2}`
        let element = document.querySelector(`#step-${step-1}`).appendChild(div_2)
        console.log(element)
        console.log('\n Required Root is '+ x2);

        document.getElementById("hasil-ahkir").innerText = x2 
    }
}

function secant(x0,x1,e,n) {
    let step = 0
    let x2
    console.log('\n\n*** SECANT METHOD IMPLEMENTATION ***')
    step = 1
    flag = 1

    condition = true
    while (condition) {
        if(f(x0) == f(x1)){
            console.log("divide by zero EROR");
            break;
        }

        x2 = x0 - (x1-x0)*f(x0)/( f(x1) - f(x0) )

        console.log(`Iteration-${step}, x2 = ${x2} and f(x2) = ${f(x2)}'`);
        let div = document.createElement("div")
        div.classList.add("step-result-container")
        div.setAttribute("id",`step-${step}`)
        div.innerHTML = `<div class="step-result">Langkah ke-${step} x = ${x2} , f(x) = ${f(x2)} </div>`
 
        container.appendChild(div)
        x0 = x1
        x1 = x2
        step = step + 1

        if (step > n){
            print('Not Convergent!')
            break
        }

        condition = Math.abs(f(x2)) > e
    }

    let div_2 = document.createElement("div")
        div_2.classList.add("step-result")
        div_2.innerHTML = `<b>X </b> : ${x2}`
        let element = document.querySelector(`#step-${step-1}`).appendChild(div_2)
        console.log(element)
        console.log('\n Required Root is '+ x2);

        document.getElementById("hasil-ahkir").innerText = x2 

}