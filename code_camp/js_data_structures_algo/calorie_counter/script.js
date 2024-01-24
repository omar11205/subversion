const calorieCounter = document.getElementById('calorie-counter');
const budgetNumberInput = document.getElementById('budget');
const entryDropdown = document.getElementById('entry-dropdown');
const addEntryButton = document.getElementById('add-entry');
const clearButton = document.getElementById('clear');
const output = document.getElementById('output');
let isError = false;
//validating data throught this function consumes a lot of memory

function cleanInputString2(str ){
    const strArray = str.split('');
    let cleanStrArray = [];
    for (let i = 0; i<strArray.length; i++){
        if (!["+", "-", " "].includes(strArray[i])) {
            cleanStrArray.push(strArray[i])
        }
    }
    return strArray;
}

//so a valid option can be work with regex
function cleanInputString(str ){
    const regex = /[+-\s]/g;
    return str.replace(regex, "");
}

//filter the exponential entries in HTML
function isInvalidInput(str){
    //const regex = /[0-9]+e[0-9]+/i;
    const regex = /\d+e\d+/i;
    return str.match(regex);
}

//add entries to the calorie counter
function addEntry(){
    const targetInputContainer = document.querySelector(`#${entryDropdown.value} .input-container`);
    //contiene el número de entradas de tipo texto que hay actualmente
    const entryNumber = targetInputContainer.querySelectorAll('input[type="text"]').length+1;
    //el 'enter' es necesario pues javascript lo interpreta como una nueva línea
    const HTMLString = `
    <label for="${entryDropdown.value}-${entryNumber}-name">Entry ${entryNumber} Name</label>
    <input type="text" placeholder="Name" id="${entryDropdown.value}-${entryNumber}-name">
    <label for="${entryDropdown.value}-${entryNumber}-calories">Entry ${entryNumber} Calories</label>
    <input type="number" min="0" placeholder="Calories" id="${entryDropdown.value}-${entryNumber}-calories">`;
    targetInputContainer.insertAdjacentHTML("beforeend", HTMLString);
}

function calculateCalories(e){
    /*You will be attaching this function to the submit event of the form. The submit event is triggered when the form is submitted. The default action of the submit event is to reload the page. You need to prevent this default action using the preventDefault() method of your e parameter. */
    e.preventDefault();
    isError = false;
    const breakfastNumberInputs = document.querySelectorAll('#breakfast input[type=number]');
    const lunchNumberInputs = document.querySelectorAll('#lunch input[type=number]');
    const dinnerNumberInputs = document.querySelectorAll('#dinner input[type=number]');
    const snacksNumberInputs = document.querySelectorAll('#snacks input[type=number]');
    const exerciseNumberInputs = document.querySelectorAll('#exercise input[type=number]');

    const breakfastCalories = getCaloriesFromInputs(breakfastNumberInputs);
    const lunchCalories = getCaloriesFromInputs(lunchNumberInputs);
    const dinnerCalories = getCaloriesFromInputs(dinnerNumberInputs);
    const snacksCalories = getCaloriesFromInputs(snacksNumberInputs);
    const exerciseCalories = getCaloriesFromInputs(exerciseNumberInputs);
    //necesito un nodelist o un array para pasar como argumento para getCaloriesFromInputs 
    //budgetNumberInput no es array, entonces hay que forzarlo encerrandolo en []
    const budgetCalories = getCaloriesFromInputs([budgetNumberInput]);
    if (isError){
        return;
    }
    let consumedCalories = breakfastCalories + lunchCalories + dinnerCalories + snacksCalories;
    let remainingCalories = budgetCalories-consumedCalories+exerciseCalories;
    const surplusOrDeficit = remainingCalories>=0 ? 'Surplus' : 'Deficit';
    output.innerHTML = `<span class="${surplusOrDeficit.toLowerCase()}">${Math.abs(remainingCalories)} Calorie ${surplusOrDeficit}</span>
    <hr>
    <p>${budgetCalories} Calories Budgeted</p>
    <p>${consumedCalories} Calories Consumed</p>
    <p>${exerciseCalories} Calories Burned</p>
    `;
    output.classList.remove('hide');
}

function clearForm(){
    const inputContainers = Array.from(document.querySelectorAll(".input-container"));
    for (let i = 0; i<inputContainers.length; i++){
        inputContainers[i].innerHTML = "";
    }
    budgetNumberInput.value = "";
    output.innerText = "";
    output.classList.add("hide");
}

addEntryButton.addEventListener("click", addEntry);
calorieCounter.addEventListener("submit", calculateCalories);
clearButton.addEventListener("click", clearForm);

function getCaloriesFromInputs(list){
    let calories = 0;
    for (let i = 0;i<list.length;i++){
        const currVal = cleanInputString(list[i].value);
        invalidInputMatch = isInvalidInput(currVal);
        if (invalidInputMatch){
            alert(`Invalid Input: ${invalidInputMatch[0]}`);
            isError = true;
            return null;
        }
        calories += Number(currVal);
    }
    return calories;
}

