var isUgly = function(num) {
    if(num<=0) return false; 
    while(parseInt(num/2)===num/2) { num/=2; }  // using the fact that 
    while(parseInt(num/3)===num/3) { num/=3; }  // multiplication is commutative, 
    while(parseInt(num/5)===num/5) { num/=5; }  // hence the order doesn't matter
    return num===1;
};
console.log(isUgly(1));
console.log(isUgly(14));
console.log(isUgly(6));
console.log(isUgly(100));