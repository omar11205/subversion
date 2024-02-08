const range = (start, end) => Array(end - start + 1).fill(start);
//.map((element, index)=>element + index);

//convert start and end to charaters
const charRange = (start, end) => range(start.charCodeAt(0), end.charCodeAt(0)).map((code)=>String.fromCharCode(code));

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
};

console.log("output of range: ", range(1,4));
//console.log("output of charRange: ", charRange('A','D'));

