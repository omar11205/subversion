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
    const median = getMedian(numbers);
    const mode = getMode(numbers);
    const range = getRange(numbers);

    document.querySelector("#mean").textContent = mean;
    document.querySelector("#median").textContent = median;
    document.querySelector("#mode").textContent = mode;
    document.querySelector("#range").textContent = range;
}

function getMean (array){
    //to get the mean, reduce can be used to aply a function that add every element to an argument called "accumulator" the accumulator is the second argument and it's initialized in 0 
    const sum = array.reduce((acc, el)=> acc + el, 0);
    const mean = sum/array.length;
    return mean;
}

const getMeanV2 = (array) => array.reduce((acc, el) => acc + el, 0)/array.length;

const getMedian = (array) => {
    const sorted = array.sort((a,b)=>a-b);
    const median = array.length % 2 === 0 ? getMean([sorted[array.length / 2], sorted[array.length / 2 - 1]]) : sorted[Math.floor(array.length / 2)];
    return median;
};

/* The mode is the number with the highest tally. It's ok if there is more than one mode. And if all numbers occur the same number of times there is no mode. */
const getMode = (array) => {
    const counts = {};
    /* from ChatGPT: counts[el] = (counts[el] || 0) + 1;: For each element (el) in the array, this line either initializes or increments the count of that element in the counts object. It checks if counts[el] exists. If it does, it increments the count by 1, otherwise, it initializes the count to 1. */ 
    array.forEach((el)=>{counts[el] = (counts[el] || 0)+1});
    console.log("counts object ", counts);
    // if every value appears the same number of times, there is no mode. To calculate this, you will use a Set. A Set is a data structure that only allows unique values. If you pass an array into the Set constructor, it will remove any duplicate values. If the size property of this Set is equal to 1, that tells you every value appears the same number of times. In this case, return null from your function.
    if(new Set(Object.values(counts)).size === 1){
        return null;
    }

    /*Now you need to sort the values properly. Chain the .sort() method to your Object.keys() call.For the callback, you'll need to use the counts object to compare the values of each key. You can use the a and b parameters to access the keys. Then, return the value of counts[b] minus the value of counts[a].Finally, access the first element in the array using bracket notation to complete your highest variable.*/ 
    //sort in descending order the keys of the object counts and stores in 'highest' the highest key
    const highest = Object.keys(counts).sort((a,b)=>counts[b]-counts[a])[0];
    console.log("highest: ", highest);
    /*Now chain the filter method to your latest Object.keys() call. The callback function should return whether the value of counts[el] is equal to your counts[highest].*/ 
    const mode = Object.keys(counts).filter((el)=>counts[el] === counts[highest]);
    return mode.join(", ");

}

const getRange = (array) => Math.max(...array) - Math.min(...array);

const getVariance = (array) => {
  const mean = getMean(array);
  const differences = array.map(el => el - mean);
  const squaredDifferences = differences.map((el)=>el ** 2);
};


