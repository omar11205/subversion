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
    // Regular expression to validate US phone number format
    //https://developerking.medium.com/how-to-integrate-international-phone-number-validation-in-input-field-with-javascript-55d8e4b432c4
    const phoneRegex = /^1?\s?(\d{3}|\(\d{3}\))-?\s?\d{3}-?\s?\d{4}$/gm;
    return phoneRegex.test(phoneNumber);
}