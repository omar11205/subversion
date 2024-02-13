const userInput = document.getElementById("user-input");
const checkBtn = document.getElementById("check-btn");
const clearBtn = document.getElementById("clear-btn");
const resultsDiv = document.getElementById("results-div");

checkBtn.addEventListener("click", function() {
    const phoneNumber = userInput.value.trim();

    if (phoneNumber === "") {
        alert("Please provide a phone number.");
        return;
    }

    if (validatePhoneNumber(phoneNumber)) {
        resultsDiv.textContent = `Valid US number: ${userInput.value}`;
    } else {
        resultsDiv.textContent = `Invalid US number: ${userInput.value}`;
    }
});

clearBtn.addEventListener("click", function() {
    resultsDiv.textContent = "";
    userInput.value = "";
});

function validatePhoneNumber(phoneNumber) {
    //https://techpen.dev/blog/how-to-create-a-telephone-number-validator/

    //to avoid the use of alphabetical characters (a-z) use: '\d' to only match decimals

    //for the case: 555-555-5555
    //use '\d{3}' that means 'whatever decimal 3 times continuous'
    //something like 'ddd' ; for the hyphen (-) add '-', so till now: '\d{3}-',
    //extending the logic: '\d{3}-\d{3}-\d{4}' 
    //and this will match ddd-ddd-dddd
    const phoneRegexCond1 = /\d{3}-\d{3}-\d{4}/;

    //for the case: (555)555-5555
    //include a regular expression that tells the validator to match 3 digits without brackets and a hyphen '-' OR three digits sourrounded by  brackets,
    //something like: (ddd)'or'ddd- (or operator = '|')
    //to match 3 consecutive digits enclosed in a rouded bracket 
    //is neccesary to scape both rounded brackets wiht a '\' after the '(' or ')' so it will be something like: '\('+'\d{3}'+'\)' = \(\d{3}\)
    //then adding the OR: (ddd)'or'ddd = \d{3}|\(\d{3}\)
    //grouping the expression with (): (\d{3}|\(\d{3}\))
    //hiphen '-' is optional when the user is using 555- so for making a symbol optional next to it add '?': -?
    //for (ddd)'or'ddd-: (\d{3}|\(\d{3}\))-?
    //for the rest of the expresion 'ddd-dddd' use the same logic used in phoneRegexCond1: \d{3}-\d{4}
    //so the final expression is: /(\d{3}|\(\d{3}\))-?\d{3}-\d{4}/
    const phoneRegexCond12 = /(\d{3}|\(\d{3}\))-?\d{3}-\d{4}/;

    //for the case: (555) 555-5555 add an optional blank space next to the hyphen '-' who slpits 'ddd-dddd' in phoneRegexCond12 using the special character for blank space '\s' and the optional operator '?':  '(\d{3}|\(\d{3}\))-?\d{3}-' + '\s?' + '\d{4}' = (\d{3}|\(\d{3}\))-?\d{3}-\s?\d{4}
    const phoneRegexCond123 = /(\d{3}|\(\d{3}\))-?\d{3}-\s?\d{4}/

    //for the case 555 555 5555 update phoneRegexCond123 with an optional hyphen '-?' and an optional blank space '\s?' in all separators: 
    //'(\d{3}|\(\d{3}\))' + '-?\s?' + '\d{3}' + '-?\s?' + '\d{4}' = (\d{3}|\(\d{3}\))-?\s?\d{3}-?\s?\d{4}
    const phoneRegexCond1234 = /(\d{3}|\(\d{3}\))-?\s?\d{3}-?\s?\d{4}/;

    //for the case 5555555555 since all the logical sentences used to separate 'ddd ddd dddd' are optional ('-?\s?' and '-?\s?'), is not mandatory the ocurrence of any character in this places. In other words, '-?\s?' as separators means that if there are any character separating the digits in this positions the only characters allowed are '-' or a blank space '\d' 
    const phoneRegexCond12345 = phoneRegexCond1234;

    // for the case that 1 is used as an international indicative for US numbers: 1 dddddddddd
    // 1 is optional and constant since the international indicative for US allways will be 1: 1?
    // also there is an space that is optional for the cases when the indicative is not in use: \s?
    // '1?\s?' + '(\d{3}|\(\d{3}\))-?\s?\d{3}-?\s?\d{4}' = 1?\s?(\d{3}|\(\d{3}\))-?\s?\d{3}-?\s?\d{4}
    const phoneRegexCond123456 = /1?\s?(\d{3}|\(\d{3}\))-?\s?\d{3}-?\s?\d{4}/;

    //the regex in phoneRegexCond123456 will match all the cases mentioned but also will match: '1 allcases + some random text'
    //in example the instruction phoneRegexCond123456.test('1 1234567890ddddddddd') will return 'true' because '1 1234567890' is contained in the string 
    //to test the entire input the regex need the meta characters that indicates the start and the end of a line '^', '$' along with the global 'm' for multi line and 'g' for searching all occurences for safety
    //so the final regex is: '/^' + 'phoneRegexCond123456' + '/gm' = /^1?\s?(\d{3}|\(\d{3}\))-?\s?\d{3}-?\s?\d{4}$/gm
    const finalPhoneRegex = /^1?\s?(\d{3}|\(\d{3}\))-?\s?\d{3}-?\s?\d{4}$/gm

    return finalPhoneRegex.test(phoneNumber);
}