const sortButton = document.getElementById("sort");
const sortInputArray = (event) => {
    //You will be using this as an event listener for the sortButton. Because buttons associated with a form element submit by default, you need to prevent that behavior.
    event.preventDefault();
    //to get the values of the select elements query them all with getElementByClassName
    //the spread operator can be used to convert the array-like object to an array
    const inputValues = [...document.getElementsByClassName("values-dropdown")].map((dropdown)=>Number(dropdown.value));
    console.log(inputValues);
    const sortedValues = bubbleSort(inputValues);
    updateUI(sortedValues);
}
//the event listeners are methods called on the element who will trigger the event
sortButton.addEventListener("click", sortInputArray);

//a fallback is a empity element that is used as a default value for a function argument

const updateUI = (array = []) => {
    array.forEach((num, i)=>{
        const outputValueNode = document.getElementById(`output-value-${i}`);
        outputValueNode.innerText = num;
    }); 
}

const bubbleSort = (array) => {
    for (let i = 0; i < array.length; i++) {
      for (let j = 0; j < array.length - 1; j++) {
        console.log(array, array[j], array[j + 1]);
        if (array[j] > array[j + 1]) {
          const temp = array[j];
          array[j] = array[j + 1];
          array[j + 1] = temp;
        }
      }
    }
    return array;
  }
