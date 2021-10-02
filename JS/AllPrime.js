let args = process.argv;
let n = parseInt(args[2])



for (let i = 1; i <= n; i++){
    let isPrime = IsPrime(i)
    if (isPrime == true) {
        console.log(i)
    }
   
}
function IsPrime(x) {
    let Prime = true
    for (let div = 2; div * div <= x; div++) {
       if (x%div == 0) {
           Prime = false
           break
            }
            else{
                Prime = true
            }

    }
    return Prime
}