const forumLatest = "https://forum-proxy.freecodecamp.rocks/latest";
const forumTopicUrl = "https://forum.freecodecamp.org/t/";
const forumCategoryUrl = "https://forum.freecodecamp.org/c/";
const avatarUrl = "https://sea1.discourse-cdn.com/freecodecamp";

const postsContainer = document.getElementById("posts-container");

/* To populate the forum leaderboard with data, you will need to request the data from an API. This is known as an asynchronous operation, which means that tasks execute independently of the main program flow.

You can use the async keyword to create an asynchronous function, which returns a promise. */

//const fetchData = async () => {};

/* In the last project, you used the .catch() method to handle errors. Here you'll use a try...catch statement instead.

The try block is designed to handle potential errors, and the code inside the catch block will be executed in case an error occurs. */

/*const fetchData = async () => {
    try {

    } catch (err) {

    }
};*/

/*In the previous project, you used fetch() with the .then() method to perform logic after the promise was resolved. Now you will use the await keyword to handle the asynchronous nature of the fetch() method.

The await keyword waits for a promise to resolve and returns the result.*/


const fetchData = async () => {
    try {
        const res = await fetch(forumLatest);
        const data = await res.json();
        console.log(data);
        showLatestPosts(data);
    } catch (err) {
        console.log(err);
    }
};

fetchData();

/*To display data in the Activity column, you need to use the bumped_at property of each topic, which is a timestamp in the ISO 8601 format. You need to process this data before you can show how much time has passed since a topic had any activity.*/ 

const timeAgo = (time) => {
    const currentTime = new Date();
    const lastPost = new Date(time);
    const timeDifference = currentTime - lastPost;
    const msPerMinute = 1000*60;
};


const showLatestPosts = (data) => {
    const {topic_list, users} = data;
    const {topics} = topic_list;
    postsContainer.innerHTML = topics.map((item)=>{
        const {id, title, views, posts_count, slug, posters, category_id, bumped_at} = item;
        return `
        <tr>
            <td>
                <p class="post-title">${title}</p>
            </td>
            <td></td>
            <td>${posts_count - 1}</td>
            <td>${views}</td>
            <td></td>
        </tr>
        `;
    }).join("");
};


