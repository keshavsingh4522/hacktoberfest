// In Javascript, functions can be assigned to variables in the same way that strings or arrays can. 
// They can be passed into other functions as an arguement or returned from them as well. 

//* HIGH ORDER FUNCTION :-
//? A “higher-order function” is a function that (i) may or may not accepts functions as an arguement or (ii) may or may not returns a function.
//? (i) or (ii) ie atleast one statement must be true for a func to become HOF.

//? EXAMPLE 1
//? either the function which is used is fully defined here itself while returning in HOF without taken the func as an args


// function calculate(a){
//     return function mult(b){
//         console.log(a);
//         console.log(b);
//         console.log(a*b);
//     }
// }

// calculate(2)(3);

    // OR

// const ans = sum(2);
// ans(3);


//? EXAMPLE 2
//? or we can define the function first and just call it in High order Function when taken as arg

//* (i)

// function concatt(b){
//     console.log("hello" + b);
// }

// function solve(a,operator){
//     return operator(a);
// }

// solve(2,concatt);


//* (ii)

// const add = (a,b)=> console.log(a+b);

// const product = (a,b)=> console.log(a*b);

// function calculator(d,e,operator){
//     return operator(d,e);
// }

// calculator(4,5,product);


// The concepts of higher-order functions and curried functions are generally used in an orthogonal way.
// A higher-order function is simply a function that takes a function as an argument or returns a function as a result, and it may or may not be curried. 
// In general usage, someone referring to a higher-order function is usually talking about a function that takes another function as an argument.



//* Currying :-
//? It is a technique of evaluating function with multiple args, into sequence of function with single argument.

//* Detailed Explaination
// In other words when a function instead of taking all args at one time, take the first one
//and return a new funtion that takes the second one and return a new function that takes the third one and so on 
// until all args have been fulfilled


//? for ex :- when we turn a function  call add(1,2,3) into add(1)(2)(3) is called currying.

//* Curried Function :-
//? A curried function, on the other hand, is one that returns a function as its result. A fully curried function is a one-argument function that either returns an ordinary result or returns a fully curried function. 

//* Note 
//? 1.  A curried function is necessarily a higher-order function, since it returns a function as its result.
//? 2.  A higher order function may or may not be curried function but a curried function is always a higher order function


//* High Order Functions can be

//* an anonymous function

// function funA(a){
//     return function(b){
//         return function(c){
//             return function(d){
//                 console.log(a,b,c,d);
//             }
//         }
//     }
// }

// OR


//* a normal function

// function funA(a){
//     return function funB(b){
//         return function funC(c){
//             return function funD(d){
//                 console.log(a,b,c,d);
//             }
//         }
//     }
// }


// funA(2)(3)(4)(5);

// OR 


//* a fat arrow =>() function

// because single line in => function does not need return keyword

// const funA = (a)=> (b)=> (c)=> (d)=> a+b+c+d;

// console.log(funA(2)(3)(4)(5));




//?  The upper three condition are there if there is no function as an args
//? But if a func is taken as an args then :-

// const subs = (a,b) => {
//     return Math.abs(a-b);
// }
// const mult = (a,b) => {
//     return a*b;
// }

// const calculator = (num1,num2, operator) => {
//   return operator(num1,num2);
// }

//? its normal like this as we are taking the function as an args before returning it
//? As the method of returning a function is same either its anonymous, normal or fat arrow.





//*  NOW DIFFERENCE BETWEEN HIGH ORDER FUNCTION AND CALLBACK FUNCTION :-

//* Callback Function :- 
//? The function which gets passed as an arguement is called a callback function.

//* Higher Order Function :-
//? The function which takes a function as an arguement is called Higher Order Function.


//* EXAMPLE

// function hi(){
//     console.log("i am going to be a callback function when passed as an argument in hello function");
// }

// function hello(another){
//     console.log("I became a higher order function as I take the function hi as an arguement");
//     return another();
    
// }

// hello(hi);

//? hi :-  Callback Function
//? hello :- Higher Order Function



//* Points To Remember :-
//? 1. HOF function may or may not takes one or more functions as an arguement.
//? 2. HOF function may or may not return another function.


//* Important Note :-
//TODO A function needs to pass atleast one of the two point described above to become a higher order function.