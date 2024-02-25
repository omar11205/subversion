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
    const minutesAgo = Math.floor(timeDifference/msPerMinute);
    const hoursAgo = Math.floor(minutesAgo/60);
    const daysAgo = Math.floor(hoursAgo/24);
    if (minutesAgo < 60){
        return `${minutesAgo}m ago`;
    }
    if (hoursAgo<24){
        return `${hoursAgo}h ago`;
    }
    return `${daysAgo}d ago`;
};

/*You need a function to convert view counts to a more readable format. For example, if the view count is 1000, it should display as 1k and if the view count is 100,000 it should display as 100k.*/

const viewCount = (views) => {
    const thousands = Math.floor(views/1000);
    if (views >= 1000){
        return `${thousands}k`;
    }
    return views;
};

/* Each of the forum topics includes a category like Python or JavaScript. In the next few steps, you will build out a category object which holds all of the forum categories and classNames for the styling. */

const allCategories = {
    299: {category: "Career Advice", className: "career"},
    409: { category: "Project Feedback", className: "feedback" },
    417: {category: "freeCodeCamp Support", className: "support"},
    421: { category: "JavaScript", className: "javascript" },
    423: { category: "HTML - CSS", className: "html-css" },
    424: { category: "Python", className: "python" },
    432: { category: "You Can Do This!", className: "motivation" },
    560: { category: "Backend Development", className: "backend" },
};

const forumCategory = (id) => {
    let selectedCategory = {};
    if (allCategories.hasOwnProperty(id)){
        const {className, category} = allCategories[id];
        selectedCategory.className = className;
        selectedCategory.category = category;
    } else {
        selectedCategory.className = "general";
        selectedCategory.category = "General";
        selectedCategory.id = 1;
    }

    const url = `${forumCategoryUrl}${selectedCategory.className}/${id}`;
    const linkText = selectedCategory.category;
    const linkClass = `category ${selectedCategory.className}`;
    return `<a href="${url}" class="${linkClass}" target="_blank">${linkText}</a>`;
};

/*Each forum post will include a list of user avatar images which represent all of the users participating in the conversation for that topic.*/

const avatars = (posters, users) => {
    return posters.map((poster)=>{
        const user = users.find((user)=>user.id===poster.user_id);
        if(user){
            const avatar = user.avatar_template.replace(/{size}/, 30);
            const userAvatarUrl = avatar.startsWith("/user_avatar/") ? avatarUrl.concat(avatar) : avatar;
            return `<img src="${userAvatarUrl}" alt="${user.name}">`;
        }
    }).join("");
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
                ${forumCategory(category_id)}
            </td>
            <td>
                <div class="avatar-container">${avatars(posters, users)}</div>
            </td>
            <td>${posts_count - 1}</td>
            <td>${viewCount(views)}</td>
            <td>${timeAgo(bumped_at)}</td>
        </tr>
        `;
    }).join("");
};


