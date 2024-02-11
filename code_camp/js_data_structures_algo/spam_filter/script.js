const messageInput = document.getElementById("message-input");
const result = document.getElementById("result");
const checkMessageButton = document.getElementById("check-message-btn");


checkMessageButton.addEventListener('click', ()=>{
    if (messageInput.value === ''){
        alert("Please enter a message.");
        return;
    }
    result.textContent = isSpam(messageInput.value)
    ? "Oh no! This looks like a spam message."
    : "This message does not seem to contain any spam.";
    messageInput.value = "";
});

//the alternate sequence | can be usede to match either the texto on the left or the right of |
const helpRegex = /please help|assist me/i;
//character clases are used for agrouping terms [a-z].
//+ is used for match one or more consecutive terms
//() capture groups are used to group matches
// ? the quantifier matches zero or more ocurrence of the preceding chararter or group
// if i dont need to store the match in a group i can use (?:) at the beginning of the group to create a non-capturing group
const dollarRegex = /[0-9]+ (?:hundred|thousand|million|billion)? dollars/i;
//\s check for spaces (used for not mach composed words like money-free)
//(?:^|\s) and (?:$|\s) are non capturing groups to match spaces or no spaces in the beginning or the end of the string
const freeRegex = /(?:^|\s)fr[e3][e3] m[o0]n[e3]y\s(?:$|\s)/i;
const stockRegex = /[s5][t7][o0][c{[(]k [a@4]l[e3]r[t7]/i;
const dearRegex = /(?:^|\s)d[e3][a@4]r fr[i1|][e3]nd(?:$|\s)/i;

const denyList =[helpRegex, dollarRegex, freeRegex, stockRegex, dearRegex];

//match return the string that matches
const isSpamMatch = (msg) => {msg.match(helpRegex); console.log(msg)};

//test test if regex is content in msg and returns true or false
const isSpamTest = (msg) => helpRegex.test(msg);

//some() returns true if any element of an array makes true the callback function pass to it
const isSpam = (msg) => denyList.some((regex) => regex.test(msg));


