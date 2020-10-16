var bigbox = document.querySelector(".container");
var arr = document.querySelectorAll(".cont");
var message = document.querySelector(".message");
var PlayerX = document.querySelector(".PlayerX");
var PlayerY = document.querySelector(".PlayerY");

arr.forEach(toggle);
arr.forEach(disabled);

var XS = Array();
var OS = Array();
var q = 0;

PlayerX.addEventListener("click", function() {
	arr.forEach(selectX);
	arr.forEach(enabled);
})

PlayerY.addEventListener("click", function() {
	arr.forEach(selectY);
	arr.forEach(enabled);
})

function selectX(item) {
	if(item.classList.contains("circle")){
		item.classList.remove("circle");
		item.classList.add("x");
	}
	else {	
		item.classList.add("x");
	}
}

function selectY(item) {
	if(item.classList.contains("x")){
		item.classList.remove("x");
		item.classList.add("circle");
	}
	else {
		item.classList.add("circle");
	}
}

function disabled(item) {
	item.style.pointerEvents = "none";
}

function enabled(item) {
	item.style.pointerEvents = "auto";
}
function toggle(item,index) {
		var help = item.addEventListener("click", function() {
		q = q + 1;	
		PlayerX.disabled = true;
		PlayerY.disabled = true;
		if(item.classList.contains("x") && !item.classList.contains("O") && !item.classList.contains("X")) {
			item.classList.add("X");
			XS.push(index);
		}
		else {	
			item.classList.add("O");
			OS.push(index);
		}

		for(let i=0;i<arr.length;i++) {
			if(item.classList.contains("X") && arr[i]!=item) {
				arr[i].classList.remove("x");
				arr[i].classList.add("circle");
		}
		else {
			if(item.classList.contains("O") && arr[i]!=item) {
				arr[i].classList.remove("circle");
				arr[i].classList.add("x");	
			}
		}	
	}
	item.style.pointerEvents = "none";

console.log(q);
if (q==9) {0
	message.innerHTML = "Draw";
}
function check(arr) {
	var win = [[0,1,2],[0,3,6],[0,4,8],[1,4,7],[2,5,8],[2,4,6],[3,4,5],[6,7,8]];

	var array = Array();
	for(var i=0;i<win.length;i++) {

		array.push(win[i]);
		var k = 0;
		for(let j=0;j<3;j++) {
			if(arr.length !=0) {
			if(arr.includes(array[i][j])) {
				k = k + 1;
			}
			else {
				k = 0;
			}
			if(k==3) {
				q = 0;
				break;
			}
		}
		}
		if(k==3) {
			return true;
			break;
		}		
	}
}	
if(check(XS) == true){
	message.innerHTML = "X Wins";
}
if(check(OS) == true) {
	message.innerHTML = "Y Wins";
}
	})
}	