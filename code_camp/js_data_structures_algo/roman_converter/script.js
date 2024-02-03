const convertBtn = document.getElementById('convert-btn');
const numberInput = document.getElementById('number');
const outputElement = document.getElementById('output');

const romanArray = [
  [ 'M', 1000],
  ['CM',  900],
  [ 'D',  500],
  ['CD',  400],
  [ 'C',  100],
  ['XC',   90],
  [ 'L',   50],
  ['XL',   40],
  [ 'X',   10],
  ['IX',    9],
  [ 'V',    5],
  ['IV',    4],
  [ 'I',    1]
];

const convertToRoman = (number) => {
  const recur = (remainder, romanArray) => {
    if (remainder == 0){
      return '';
    } 
    const [[numeral, value], ...tail] = romanArray;
    let output = numeral.repeat(remainder / value) + recur(remainder % value, tail);
    return output;
  };
  
  return recur(number, romanArray);
};

convertBtn.addEventListener('click', () => {

  if (!numberInput.value) {
    outputElement.textContent = 'Please enter a valid number';
    return;
  } else if (parseInt(numberInput.value) < 1) {
    outputElement.textContent = 'Please enter a number greater than or equal to 1';
    return;
  } else if (parseInt(numberInput.value) >= 4000){
    outputElement.textContent = "Please enter a number less than or equal to 3999";
  } else {
    outputElement.textContent = convertToRoman(parseInt(numberInput.value));
  }

});




