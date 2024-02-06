const calculate = () => {
    //the data type of value will be a string like this "1,2,4,5,6"

    const value = document.querySelector("#numbers").value;

    //so its necesary to recover each number from the string and convert it into an array of numbers
    //split method takes an string and splits it into an array of strings ["1", "2", "4", "5", "6"]
    const array = value.split(/,\s*/g);

    //with the map method a new array is created from a previous array or an iterable data type. "el" represents every element of the array numbers, so it returns an array like this [1, 2, 4, 5, 6] 
    //remove the NaN values who will apear if a character is contained in the string array

    const numbers = array.map(el=>{return Number(el)}).filter(el => {return !isNaN(el)});
    const mean = getMean(numbers);
}

function getMean (array){
    //to get the mean, reduce can be used to aply a function that add every element to an argument called "accumulator" the accumulator is the second argument and it's initialized in 0 
    const sum = array.reduce((acc, el)=> acc + el, 0);
    const mean = sum/array.length;
    return mean;
}

const getMeanV2 = (array) => array.reduce((acc, el) => acc + el, 0)/array.length;

