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

function decimalToBinary(input){
    const base = Math.ceil(Math.log2(input));
    console.log(base);
    /*for (let i = 0; i<base; i++){

    }*/
}

convertBtn.addEventListener("click", checkUserInput);
numberInput.addEventListener("keydown", (e) => {
    if (e.key === "Enter") {
        checkUserInput();
    }
});