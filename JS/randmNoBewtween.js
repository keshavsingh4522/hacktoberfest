/**
 * Generates a random number between numbers minNo and maxNo.
 * @param {number} minNo - smallest number of the range.
 * @param {number} maxNo - largest number of the range.
 */

function randomNoBetween(minNo, maxNo) {
  return Math.floor(Math.random() * (maxNo - minNo + 1) + minNo);
}

// random number between 200-500
console.log(randomNoBetween(200, 500));

// random number between 200-600
console.log(randomNoBetween(200, 600));

// random number between 500-800
console.log(randomNoBetween(500, 800));
