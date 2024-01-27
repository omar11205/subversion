const checkBtn = document.getElementById('check-btn');
const textInput = document.getElementById('text-input');
const resultDiv = document.getElementById('result');

function isPalindrome(str) {
    const cleanStr = str.replace(/[^a-zA-Z0-9]/g, '').toLowerCase();
    return cleanStr === cleanStr.split('').reverse().join('');
}

checkBtn.addEventListener('click', function () {
  const inputValue = textInput.value.trim();
  if (inputValue === '') {
    alert('Please input a value');
  } else if(isPalindrome(inputValue)){
    resultDiv.textContent = `${inputValue} is a palindrome`;
  } else {
    resultDiv.textContent = `${inputValue} is not a palindrome`;
  }
});
