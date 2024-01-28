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
    buttonEl.parentElement.remove();
    taskData.splice(dataArrIndex, 1);
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
    if (formInputsContainValues){
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




console.log(taskData);

console.log(currentTask);

