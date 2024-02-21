const listOfAllDice = document.querySelectorAll(".die");
const scoreInputs = document.querySelectorAll("#score-options input");
const scoreSpans = document.querySelectorAll("#score-options span");
const currentRoundText = document.getElementById("current-round");
const currentRoundRollsText = document.getElementById("current-round-rolls");
const totalScoreText = document.getElementById("total-score");
const scoreHistory = document.getElementById("total-hystory");
const rollDiceBtn = document.getElementById("roll-dice-btn");
const keepScoreBtn = document.getElementById("keep-score-btn");
const rulesContainer = document.querySelector(".rules-container");
const rulesBtn = document.getElementById("rules-btn");

let isModalShowing = false;
let diceValuesArr = [];
let score = 0;
let totalScore = 0;
let round = 1;
let rolls = 0;

//functionality to show the ruless to display on the screen 
rulesBtn.addEventListener("click", ()=>{
    //every time the user clicks on the rules button, the current boolean value 
    //for isModalShowing toggle between true and false
    isModalShowing = !isModalShowing;
    if(isModalShowing){
        rulesBtn.textContent = "Hide Rules";
        rulesContainer.style.display = "block";
    } else {
        rulesBtn.textContent = "Show Rules";
        rulesContainer.style.display = "none";
    }

});

const rollDice = () =>{
    diceValuesArr = [];
    //when the user rolls the dice, you will need to generate 5 random numbers 
    //representing each dice value
    for (let i = 0; i<5; i++){
        //for each iteration of the loop you will need to generate a random number
        //that represents one of the six possible values found on a dice
        const randomDice = Math.floor(Math.random() * 6) + 1;
        diceValuesArr.push(randomDice);
    }
    //forEach() calls a function for each element in an array
    listOfAllDice.forEach((dice, noindex)=>{
        dice.textContent = diceValuesArr[noindex];
        //console.log("Current value of index inside forEach: ", noindex);
    });
};

const updateStats = () => {
    currentRoundRollsText.textContent = rolls;
    currentRoundText.textContent = round;
};

const updateRadioOption = (optionNode, score)=>{
    scoreInputs[optionNode].disabled = false;
    scoreInputs[optionNode].value = score;
    //To display the current score, update the text content for the span element next to the radio button to be the following template literal
    scoreSpans[optionNode].textContent = `, score = ${score}`;
}

//algorithm that tracks any duplicates found in diceValuesArr and displays a score next to the first two radio buttons
let getHighestDuplicates = (arr) => {
    //count the number of occurrences for each unique number in the arr
    const counts = {};
    for (const num of arr){
        /* For each iteration in the arr, you will need to check if the current number exists in the counts object. If not, start with 1.*/ 
        if(counts[num]){
            counts[num]++
        } else {
            counts[num] = 1;
        }
    }
    //tracks of when a particular number appears tree of four times within the arr
    let highestCount = 0;

    for (const num of arr){
        const count = counts[num];

        //Tree of a kind
        if (count >= 3 && count > highestCount){
            highestCount = count;
        }
        //Four of a kind
        if (count >= 3 && count > highestCount){
            highestCount = count;
        }
        
    }

    //If the user rolls a "Three of a kind" or "Four of a kind", then they will receive a score totalling the sum of all five dice values.  
    const sumOfAllDice = diceValuesArr.reduce((a,b)=>a+b, 0);
        
    if(highestCount >= 4){   
        updateRadioOption(1, sumOfAllDice);  
    }

    if (highestCount >= 3){
        updateRadioOption(0, sumOfAllDice);
    }

    //If the user does not get a "Three of a kind" or "Four of kind", then they will not receive any points for that round.
    updateRadioOption(5, 0);
    console.log(highestCount);


};


rollDiceBtn.addEventListener("click", ()=>{
    //For each round in the game, users are allowed to roll the dice a maximum of three times.
    if(rolls === 80){
        alert("You have made three rolls this round. Please select a score.");
    } else {
        rolls++;
        rollDice();
        updateStats();
        getHighestDuplicates(diceValuesArr);
    }
});





