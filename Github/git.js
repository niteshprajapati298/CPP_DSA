// Utility functions in JavaScript

// 1. Add two numbers
function add(a, b) {

return a+b;
}

// 2. Check if a number is even
function isEven(num) {
  return num % 2 === 0;
}

// 3. Find the maximum value in an array
function findMax(arr) {
  if (arr.length === 0) return null;
  return Math.max(...arr);
}

// 4. Reverse a string
function reverseString(str) {
  return str.split('').reverse().join('');
}

// 5. Check if a string is a palindrome
function isPalindrome(str) {
  const cleaned = str.toLowerCase().replace(/[^a-z0-9]/g, '');
  return cleaned === cleaned.split('').reverse().join('');
}

// 6. Filter array based on condition
function filterArray(arr, condition) {
  return arr.filter(condition);
}

// 7. Map array elements
function mapArray(arr, transform) {
  return arr.map(transform);
}

// 8. Count occurrences of a character in a string
function countChar(str, char) {
  return str.split(char).length - 1;
}

// 9. Generate a random number between min and max
function randomNumber(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

// 10. Capitalize first letter of a string
function capitalize(str) {
  return str.charAt(0).toUpperCase() + str.slice(1);
}

// Example usage
console.log("Add 5 + 3:", add(5, 3));
console.log("Is 10 even?", isEven(10));
console.log("Max of [1, 5, 3, 9, 2]:", findMax([1, 5, 3, 9, 2]));
console.log("Reverse 'hello':", reverseString('hello'));
console.log("Is 'racecar' palindrome?", isPalindrome('racecar'));
console.log("Random number between 1-100:", randomNumber(1, 100));
console.log("Capitalize 'javascript':", capitalize('javascript'));
