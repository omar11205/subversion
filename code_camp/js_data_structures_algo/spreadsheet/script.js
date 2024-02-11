const infixToFunction = {
    "+": (x, y) => x + y,
    "-": (x, y) => x - y,
    "*": (x, y) => x * y,
    "/": (x, y) => x / y,
}

const infixEval = (str, regex) => str.replace(regex, (_match, arg1, operator, arg2) => infixToFunction[operator](parseFloat(arg1), parseFloat(arg2)));

const highPrecedence = (str) => {
    const regex = /([\d.]+)([*\/])([\d.]+)/;
    const str2 = infixEval(str, regex);
    return str === str2 ? str : highPrecedence(str2);
};

const isEven = (num) => num % 2 === 0 ? true : false;

const sum = (nums) => nums.reduce((acc, el) => acc + el, 0);

const average = (nums) => sum(nums)/nums.length;

const median = nums => {
    const sorted = nums.slice().sort((a, b) => a - b);
    const length = sorted.length;
    const middle = length / 2 - 1;
    return isEven(length) ? average([sorted[middle], sorted[middle + 1]]) : sorted[Math.ceil(middle)];
};

const spreadsheetFunctions = {
    sum,
    average,
    median
}

toLowerCase

const applyFunction = str => {
    const noHigh = highPrecedence(str);
    const infix = /([\d.]+)([+-])([\d.]+)/;
    const str2 = infixEval(noHigh, infix);
    const functionCall = /([a-z]*)\(([0-9., ]*)\)(?!.*\()/i;
    const toNumberList = args => args.split(",").map(parseFloat);
    const apply = (fn, args) => spreadsheetFunctions[fn.toLowerCase];
};

const range = (start, end) => Array(end - start + 1).fill(start).map((element, index)=>element + index);

//convert start and end to charaters
const charRange = (start, end) => range(start.charCodeAt(0), end.charCodeAt(0)).map((code)=>String.fromCharCode(code));

const evalFormula = (x, cells) => {
    const idToText = id => cells.find(cell => cell.id === id).value;
    const rangeRegex = /([A-J])([1-9][0-9]?):([A-J])([1-9][0-9]?)/gi;
    const rangeFromString = (num1, num2) => range(parseInt(num1), parseInt(num2));
    /* The concept of returning a function within a function is called currying. This approach allows you to create a variable that holds a function to be called later, but with a reference to the parameters of the outer function call. */

    /* For example: curry is a function which takes a soup parameter and returns a function which takes a veggies parameter. */
    //const curry = soup => veggies => {};

    const elemValue = num => character => idToText(character + num);
    /* the callback functions for methods like .map() can be stored in variables. For example elemValue */
    const addCharacters = character1 => character2 => num => charRange(character1, character2).map(elemValue(num));
    /* Your addCharacters(char1) is also returning a function, which returns another function. You need to make another function call to access that innermost function reference for the .map() callback. JavaScript allows you to immediately invoke returned functions: Immediately invoke the function returned from your addCharacters(char1) call, and pass char2 as the argument. */ 
    // for unused parameters underscoreit: "_parameter"
    const rangeExpanded = x.replace(rangeRegex, (_match, char1, num1, char2, num2) => rangeFromString(num1, num2).map(addCharacters(char1)(char2)));
    const cellRegex = /[A-J][1-9][0-9]?/gi;
    const cellExpanded = rangeExpanded.replace(cellRegex, match => idToText(match.toUpperCase()));

}

window.onload = () => {
    const container = document.getElementById("container");
    const createLabel = (name) => {
        const label = document.createElement("div");
        label.className = "label";
        label.textContent = name;
        container.appendChild(label);
    };
    const letters = charRange('A', 'J');
    letters.forEach(createLabel);
    range(1, 99).forEach(number => {
        createLabel(number);
        letters.forEach(letter => {
          const input = document.createElement("input");
          input.type = "text";
          input.id = letter + number;
          input.ariaLabel = letter + number;
          input.onchange = update;
          container.appendChild(input);
        })
    })
};

const update = (event) => {
    const element = event.target;
    const value = element.value.replace(/\s/g, "");
    if (!value.includes(element.id) && value.startsWith('=')){}
}
console.log("output of range: ", range(1,4));
console.log("output of charRange: ", charRange('A','D'));

