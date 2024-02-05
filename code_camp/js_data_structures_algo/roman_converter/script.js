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

const convertToRoman = (arabic) => {
  const recur = (residual, romanArray) => {
    if (residual == 0){
      return '';
    } 
    const [[romanLetter, equivalent], ...rest] = romanArray;
    let output = romanLetter.repeat(residual / equivalent) + recur(residual % equivalent, rest);
    console.log("Output ", output);
    return output;
  };

  return recur(arabic, romanArray);
};

const convertToRomanTest = () => {
  const [[numeral, value], ...tail] = romanArray;
  let output = numeral.repeat(1);
  console.log(numeral);
  console.log(value);
  console.log(tail);
  console.log(output);
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




