const authorContainer = document.getElementById("author-container");
const loadMoreBtn = document.getElementById("load-more-btn");

/*The Fetch API is a built-in JavaScript interface to make network requests to a server. It has a fetch() method you can use to make GET, POST, PUT, or PATCH requests. In this project, you'll make a GET request to a URL for a JSON file with information about authors on freeCodeCamp News.*/ 

/*The fetch() method returns a Promise, which is a placeholder object that will either be fulfilled if your request is successful, or rejected if your request is unsuccessful.*/ 

/*If the Promise is fulfilled, it resolves to a Response object, and you can use the .then() method to access the Response.*/ 

/*The data you get from a GET request is not usable at first. To make the data usable, you can use the .json() method on the Response object to parse it into JSON. If you expand the Prototype of the Response object in the console, you will see the .json() method there.*/ 

//fetch("https://cdn.freecodecamp.org/curriculum/news-author-page/authors.json").then((res)=>console.log(res))

//fetch("https://cdn.freecodecamp.org/curriculum/news-author-page/authors.json").then((res)=>res.json())

/*In order to start working with the data, you will need to use another .then() method.*/ 

//fetch("https://cdn.freecodecamp.org/curriculum/news-author-page/authors.json").then((res)=>res.json()).then((data)=>{console.log(data)});

/*The .catch() method is another asynchronous JavaScript method you can use to handle errors. This is useful in case the Promise gets rejected.*/ 

let startingIndex = 0;
let endingIndex = 8;
let authorDataArr = [];

fetch("https://cdn.freecodecamp.org/curriculum/news-author-page/authors.json")
    .then((res)=>res.json())
    .then((data)=>{
        authorDataArr = data;
        console.log("Author Data Array:", authorDataArr);
        displayAuthors(authorDataArr.slice(startingIndex, endingIndex));
    })
    .catch((err)=>{
        console.error(`There was an error: ${err}`);
});

/*Now that you have the data you want, you can use it to populate the UI. But the fetched data contains an array of 26 authors, and if you add them all to the page at the same time, it could lead to poor performance.

Instead, you should add 8 authors at a time, and have a button to add 8 more until there's no more data to display.*/

/*Now you'll create a function to populate the UI with the author data. You will call this function inside the second .then() method.*/ 

const displayAuthors=(authors)=>{
    authors.forEach(({author, image, url, bio}, index)=>{
        authorContainer.innerHTML += `
            <div id="${index}" class="user-card">
                <h2 class="author-name">${author}</h2>
            </div>
        `;
    });
};