_('answer').focus();
_('slideBar').value='10';
var limit,num1,num2,count=10,idd,temp=1,temp2=true,boxNo,commentNo;
var solution,answered=0,temp3=1,angle=-45,ranger=10,lengthRem = 0;
var operators = ['+']
var commentArray = ["Fabulous","Awesome","Perfect","Amazing","It's your Time","Stylish","Bullseye","Sweet","Adengappa","Winner"];


//Function for my Convinence
function _(id){
	return document.getElementById(id);
}

//Function for showing Range in RangeBar

function range(){
	ranger = _("slideBar").value;
	_("value").innerText = ranger;
	angle=(_("slideBar").value*0.9)-9;
	_('showRange').style.transform="rotate("+angle+"deg)";
	_('value').style.transform="rotate(-"+angle+"deg)";
	createQuestion();
}
range();

//Function to create a random number

function rNo(limit){
	return Math.round(Math.random()*limit)+1;
}

//Function to Show the CountDown

function timer(){
	_("time").innerText = count;
	_("time").innerHTML += "<span id='remTime'>Second(s) left !</span>";
	count--;
	// if(count<10){
	// 		lengthRem+=25;
	// 		_("lengthBar").style.width = lengthRem+"px";
	// 	}
	idd=setTimeout(timer,1000)
	
	if(count == -1){
		_("score1").innerHTML = "<span style='font-size:30px;display:block;line-height:40px;'>Score</span>"+answered+"</span>";
		_('question').style.display = "none";
		_('answer').style.display = 'none';
		_('scoreBox').style.display="block";

		clearTimeout(idd);

	}
}

//Function for checking the operators that are Checked

function op(operator){
	if(operators.length == 1){
		operator.checked = true;
	}
	operators = [];
	for(var i=1;i<=6;i++){
		if(_("op"+i).checked){
			operators.push(_('op'+i).value);
		}
	}
}

//Function that randomly chose a random operator

function choseOp(){
	var ran=Math.round(Math.random()*(operators.length-1));
	return(operators[ran]);
}

//Function that create questions

function createQuestion(){
	op('op1');
	_("answer").value="";
	var range = ranger;
	num1=rNo(range);
	num2=rNo(range);
	matheMaticalOperations(choseOp());
	
}
createQuestion();

//Function for Calculating the Result

function matheMaticalOperations(op){
	if(op == '+'){
		solution = num1+num2;
		_("question").innerText = num1+" "+op+" "+num2+" = ";	
	}
	else if(op == '-'){
		if(num2 > num1){
			num1+=num2;
			num2=num1-num2;
			num1-=num2;
		}
		solution = num1-num2;
		_("question").innerText = num1+" "+op+" "+num2+" = ";
	}
	else if(op == '*'){
		solution = num1*num2;
		_("question").innerText = num1+" "+op+" "+num2+" = ";
	}
	else if(op == 'root'){
		solution = num1;
		_("question").innerText = "Square root of "+(num1**2);
	}
	else if(op == 'square'){
		solution = num1**2;
		_("question").innerText = "Square of "+(num1);
	}
	else{
		solution = num1;
		_("question").innerText = (num1*num2)+ " / " +num2;
	}
}

//Function to Check answer

function checkAnswer(){
	_("answer").style.backgroundColor = "#fa5477";
	var answer=_('answer').value;
	if(answer!=''&&temp3){
		timer();
		temp3=0;
	}
	if(answer == solution){
		answered++;
		count+=2;
		_('time').innerText = count;
		_("answer").style.backgroundColor = "7ecfc0";
		createQuestion();	
		increaseLevel();
		displayComment();
	}
}

//Function for the New Game

function newGame(){
	count=9;
	answered=0;
	_('time').innerText=(count+1);
	_('question').style.display = "inline-block";
	_('answer').style.display = 'inline-block';
	_('scoreBox').style.display="none";
	createQuestion();
	temp3=1;
	ranger=10;
	_("slideBar").value = ranger;
	angle=(ranger*0.9)-9;
	_('showRange').style.transform="rotate("+angle+"deg)";
	_('value').style.transform="rotate(-"+angle+"deg)";
	_('value').innerText = ranger;
}

//Function to Increase the level of the Game

function increaseLevel(){
	if(answered%5==0){
		ranger=parseInt(ranger)+10;
		_('value').innerText = ranger;
		_("slideBar").value = ranger;
		angle=(ranger*0.9)-9;
		_('showRange').style.transform="rotate("+angle+"deg)";
		_('value').style.transform="rotate(-"+angle+"deg)";
	}
}

//Function that create the comments

function callComment(){
	boxNo = rNo(1);
	commentNo = rNo((commentArray.length)-2);
	console.log(commentNo);
}

//Function that Display the comments

function displayComment(){
	callComment();
	_("comment"+boxNo).innerHTML = "<p id='commentsWord'>- "+commentArray[commentNo]+" -</p>";
	_("commentsWord").style.top = rNo(120)+"px";
	_("commentsWord").style.left = rNo(170)+"px";
	setTimeout(disappearComment1,500);
}

//Function to disappear the comment

function disappearComment1(){
	_('commentsWord').style.opacity = '0';
	setTimeout(disappearComment2,600);
}

//Function to delete the Comment

function disappearComment2(){
	_("comment"+boxNo).innerHTML = "";
}
