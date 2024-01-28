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

//classlist.toggle("") add a new class or remove the existing class
//removes the class "hidden" to show the form
//the form overlays the addNewTask button
openTaskFormBtn.addEventListener("click", () => taskForm.classList.toggle("hidden") );

//activates a modal dialog box, asociated with the <dialog> element
closeTaskFormBtn.addEventListener("click", () => confirmCloseDialog.showModal());

//close() is a method for close a modal or a window
//Note: with one instruction { } are not necesary in the callback function
cancelBtn.addEventListener("click", () => confirmCloseDialog.close() );

//close the modal and hides again the form, so the overlay is gone and
//the addNewTast button appears again
//Note: with two instructions or more  { } are necesary in the callback function
discardBtn.addEventListener("click", () => 
    confirmCloseDialog.close(),
    taskForm.classList.toggle("hidden")
);


taskForm.addEventListener("submit", (e) => {
    //stop the browser from refreshing after submitting the form
    e.preventDefault();
});



