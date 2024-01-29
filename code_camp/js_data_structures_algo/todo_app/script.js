const taskForm = document.getElementById("task-form");
const confirmCloseDialog = document.getElementById("confirm-close-dialog");
const openTaskFormBtn = document.getElementById("open-task-form-btn");
const closeTaskFormBtn = document.getElementById("close-task-form-btn");
const addOrUpdateTaskBtn = document.getElementById("add-or-update-task-btn");
const cancelBtn = document.getElementById("cancel-btn");
const discardBtn = document.getElementById("discard-btn");
const tasksContainer = document.getElementById("tasks-container");
const titleInput = document.getElementById("title-input");
const dateInput = document.getElementById("date-input");
const descriptionInput = document.getElementById("description-input");

//array who stores the tasks
const taskData = [];

//obj who track the states (editing, discard)
let currentTask = {};

const addOrUpdateTask = () => {
    //findIndex returns the index of an element inside an array that first matches a condition
    //you need to determine whether the task being added already exists or not
    const dataArrIndex = taskData.findIndex((item) => item.id === currentTask.id );  
    const taskObj = {
        id: `${titleInput.value.toLowerCase().split(' ').join('-')}-${Date.now()}`,
        title: titleInput.value,
        date: dateInput.value,
        description: descriptionInput.value 
    };

    if (dataArrIndex === -1){
        taskData.unshift(taskObj);
    } else {
        taskData[dataArrIndex] = taskObj;
    }

    updateTaskContainer();
    reset(); 
};

const updateTaskContainer = () => {
    tasksContainer.innerHTML = '';
    taskData.forEach(({id, title, date, description}) => {
        tasksContainer.innerHTML += `
        <div class="task" id="${id}">
            <p><strong>Title: </strong>${title}</p>
            <p><strong>Date:</strong>${date}</p>
            <p><strong>Description:</strong>${description}</p>
            <button onclick="editTask(this)" type="button" class="btn">Edit</button>
            <button onclick="deleteTask(this)" type="button" class="btn">Delete</button>
        </div>
        `
    });
};

const deleteTask = (buttonEl) => {
    const dataArrIndex = taskData.findIndex((item) => item.id === buttonEl.parentElement.id);
    console.log(buttonEl.parentElement);
    buttonEl.parentElement.remove();
    taskData.splice(dataArrIndex, 1);
};

const editTask = (buttonEl) => {
    const dataArrIndex = taskData.findIndex((item) => item.id === buttonEl.parentElement.id);
    currentTask = taskData[dataArrIndex];
    titleInput.value = currentTask.title;
    dateInput.value = currentTask.date;
    descriptionInput.value = currentTask.description;
    addOrUpdateTaskBtn.innerText = "Update Task";
    taskForm.classList.toggle("hidden");
};

const reset = () => {
    titleInput.value = '';
    dateInput.value = '';
    descriptionInput.value = '';
    taskForm.classList.toggle("hidden");
    currentTask = {};
};

//classlist.toggle("") add a new class or remove the existing class
//removes the class "hidden" to show the form
//the form overlays the addNewTask button
openTaskFormBtn.addEventListener("click", () => taskForm.classList.toggle("hidden") );

//activates a modal dialog box, asociated with the <dialog> element
closeTaskFormBtn.addEventListener("click", () => {
    //formInputsContainValues checs if there is a value in titleInput or dateInput or descriptionInput forms
    const formInputsContainValues = titleInput.value || dateInput.value || descriptionInput.value;
    const formInputValuesUpdated = titleInput.value !== currentTask.title || dateInput.value !== currentTask.date || descriptionInput.value !== currentTask.description;
    if (formInputsContainValues && formInputValuesUpdated){
        confirmCloseDialog.showModal(); 
    } else {
        reset();
    }

});

//close() is a method for close a modal or a window
//Note: with one instruction { } are not necesary in the callback function
cancelBtn.addEventListener("click", () => confirmCloseDialog.close() );

//close the modal and hides again the form, so the overlay is gone and
//the addNewTast button appears again
//Note: with two instructions or more  { } are necesary in the callback function
discardBtn.addEventListener("click", () => {
    confirmCloseDialog.close();
    reset();
});


taskForm.addEventListener("submit", (e) => {
    //stop the browser from refreshing after submitting the form
    e.preventDefault();
    addOrUpdateTask();
});

const myTaskArr = [
    { task: "Walk the Dog", date: "22-04-2022" },
    { task: "Read some books", date: "02-11-2023" },
    { task: "Watch football", date: "10-08-2021" },
];

localStorage.setItem("data", myTaskArr);

//local storage prefers text, so:
localStorage.setItem("data", JSON.stringify(myTaskArr));

//to retrieve and convert to an object:
const getTaskArrObj = JSON.parse(localStorage.getItem("data"));

//to remove the data from localstorage
localStorage.removeItem("data");
//or
//localStorage.clear();
//but clear, clears all de localStorage data, so it will be dangerous



console.log(taskData);

console.log(currentTask);

