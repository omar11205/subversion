const numberInput = document.getElementById("number-input");
const convertBtn = document.getElementById("convert-btn");
const result = document.getElementById("result");

const checkUserInput = () => {
    //the values that recieves JS are allways strings, if the input is empity and is entered
    //a empity sting will be generated
    //in JavaScript, some common falsy values are null, undefined, the number 0, empity strings and NaN (non a number)
    //numberImput.value === '' is then equal to !numberImput.value so we reach the insides of an 'if' if numberInput.value is false
    //to avoid floats and special numbers like 'pi' or 'e' is usefull the function parseInt() who returns an integer from an string who contains a mathematical expresion
    if (!numberInput.value || isNaN(parseInt(numberInput.value))){
        alert("Please provide a decimal number");
        return;
    }
    decimalToBinary(parseInt(numberInput.value));
    numberInput.value = '';
}

function decimalToBinaryExplain(input){
    let inputs = [];
    let quotients = [];
    let remainders = [];
    
    if (input === 0){
        result.innerText = '0';
        return;
    }
    
    while(input>0){
        let quotient = Math.floor(input/2)
        let remainder = input % 2;
        inputs.push(input);
        quotients.push(quotient);
        remainders.push(remainder);
        input = quotient;  
    }
    console.log("Inputs: ", inputs);
    console.log("Quotients: ", quotients);
    console.log("Remainders: ", remainders);
    console.log("Floor 0.5 = ", Math.floor(0.5));
    result.innerText = remainders.reverse().join('');
}

function decimalToBinary(input){
    let binary = "";

    if (input === 0) {
      binary = "0";
    }
  
    while (input > 0) {
      binary = (input % 2) + binary;
      input = Math.floor(input / 2);
    }
  
    result.innerText = binary;
}

convertBtn.addEventListener("click", checkUserInput);
numberInput.addEventListener("keydown", (e) => {
    if (e.key === "Enter") {
        checkUserInput();
    }
});

