const numberInput = document.getElementById("number-input");
const convertBtn = document.getElementById("convert-btn");
const result = document.getElementById("result");
const animationContainer = document.getElementById("animation-container");

const animationData = [
    {
      inputVal: 5,
      marginTop: 300,
      addElDelay: 1000,
      msg: 'decimalToBinary(5) returns "10" + 1 (5 % 2). Then it pops off the stack.',
      showMsgDelay: 15000,
      removeElDelay: 20000,
    },
    {
      inputVal: 2,
      marginTop: -200,
      addElDelay: 1500,
      msg: 'decimalToBinary(2) returns "1" + 0 (2 % 2) and gives that value to the stack below. Then it pops off the stack.',
      showMsgDelay: 10000,
      removeElDelay: 15000,
    },
    {
      inputVal: 1,
      marginTop: -200,
      addElDelay: 2000,
      msg: 'decimalToBinary(1) returns "1" (base case) and gives that value to the stack below. Then it pops off the stack.',
      showMsgDelay: 5000,
      removeElDelay: 10000,
    }
];

function decimalToBinaryRecursion(input){
    if (input === 0 || input === 1) {
        return String(input);
    } else {
        return decimalToBinaryRecursion(Math.floor(input / 2)) + (input % 2);
    }
}

const showAnimation = () => {
    result.innerText = "Call Stack Animation";
  
    animationData.forEach((obj) => {
        setTimeout(() => {
            animationContainer.innerHTML += `
              <p id="${obj.inputVal}" style="margin-top: ${obj.marginTop}px;"   class="animation-frame">
                decimalToBinary(${obj.inputVal})
              </p>
            `;
        }, obj.addElDelay);
    
        setTimeout(() => {
            document.getElementById(obj.inputVal).textContent = obj.msg;
        }, obj.showMsgDelay);
    
        setTimeout(() => {
            document.getElementById(obj.inputVal).remove();
        }, obj.removeElDelay);
    });
  
    setTimeout(() => {result.textContent = decimalToBinaryRecursion(5);}, 10000);
};

const checkUserInput = () => {
    //the values that recieves JS are allways strings, if the input is empity and is entered
    //a empity sting will be generated
    //in JavaScript, some common falsy values are null, undefined, the number 0, empity strings and NaN (non a number)
    //numberImput.value === '' is then equal to !numberImput.value so we reach the insides of an 'if' if numberInput.value is false
    //to avoid floats and special numbers like 'pi' or 'e' is usefull the function parseInt() who returns an integer from an string who contains a mathematical expresion
    const inputInt = parseInt(numberInput.value);
    if (!numberInput.value || isNaN(inputInt)){
        alert("Please provide a decimal number");
        return;
    }

    if (inputInt === 5) {
        showAnimation();
        return;
    }

    result.textContent = decimalToBinaryRecursion(inputInt);
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

//recursion example
const countDown = (number) => {
    console.log(number);
    //a function who descends from a given number to 0 recursively
    //the base case is when number is equal to 0, then the function returns
    if (number === 0){
        return;
    } else {
        //Recursive functions also have a recursive case, which is where the function calls itself.
        //number - 1, the argument needs to be lowered 
        countDown(number - 1);
    }
    console.log(number);
}





convertBtn.addEventListener("click", checkUserInput);
numberInput.addEventListener("keydown", (e) => {
    if (e.key === "Enter") {
        checkUserInput();
    }
});

