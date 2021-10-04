/**
 * This function computes the first n fibonacci numbers.
 *
 * @param {number} n number of fibonacci digits, must be a finite, positive number
 * @returns an array of fibonacci numbers
 */
const firstNFibonacci = (n) => {
    // checks if the number is a valid, finite number
    if (!isFinite(n))
        return 'Please input a valid, finite number then try again.';

    let fibonacciNumbers = [];

    if (n <= 0) return fibonacciNumbers;

    fibonacciNumbers.push(0);
    if (n === 1) return fibonacciNumbers;

    fibonacciNumbers.push(1);
    if (n === 2) return fibonacciNumbers;

    while (fibonacciNumbers.length < n) {
        const lastFibonacciNumber =
            fibonacciNumbers[fibonacciNumbers.length - 1];
        const secondToLastFibonacciNumber =
            fibonacciNumbers[fibonacciNumbers.length - 2];
        fibonacciNumbers.push(
            lastFibonacciNumber + secondToLastFibonacciNumber
        );
    }

    return fibonacciNumbers;
};

console.log(firstNFibonacci(23));
