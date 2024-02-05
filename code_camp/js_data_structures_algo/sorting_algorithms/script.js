const sortButton = document.getElementById("sort");
const sortInputArray = (event) => {
    //You will be using this as an event listener for the sortButton. Because buttons associated with a form element submit by default, you need to prevent that behavior.
    event.preventDefault();
    //to get the values of the select elements query them all with getElementByClassName
    //the spread operator can be used to convert the array-like object to an array
    const inputValues = [...document.getElementsByClassName("values-dropdown")];
    inputValues.map((dropdown)=>Number(dropdown.value));
}
//the event listeners are methods called on the element who will trigger the event
sortButton.addEventListener("click", sortInputArray);

//a fallback is a empity element that is used as a default value for a function argument

const updateUI = (array = []) => {
    array.forEach((num, i)=>{});
    const outputValueNode = document.getElementById(`output-value-${i}`);
}
