const cartContainer = document.getElementById("cart-container");
const productsContainer = document.getElementById("products-container");
const dessertCards = document.getElementById("dessert-card-container");
const cartBtn = document.getElementById("cart-btn");
const clearCartBtn = document.getElementById("clear-cart-btn");
const totalNumberOfItems = document.getElementById("total-items");
const cartSubTotal = document.getElementById("subtotal");
const cartTaxes = document.getElementById("taxes");
const cartTotal = document.getElementById("total");                   
const showHideCartSpan  = document.getElementById("show-hide-cart");

let isCartShowing = false;

let products = [
    /* Before you do that, you need to consider the structure of your product data. A product will need a unique identifier to distinguish it from other products, a price so people know how much it costs, and a name so people know what they are buying. You should also add a category to each product.*/
    {
        id: 1,
        name: 'Vanilla Cupcakes (6 Pack)',
        price: 12.99,
        category: "Cupcake"
    },
    {   
        id: 2, 
        name: "French Macaroon", 
        price: 3.99, 
        category: "Macaroon" 
    },
    {   
        id: 3,
        name: "Pumpkin Cupcake", 
        price: 3.99, 
        category: "Cupcake" 
    },
    {
        id: 4,
        name: "Chocolate Cupcake", 
        price: 5.99, 
        category: "Cupcake" 
    },
    { 
        id: 5,
        name: "Chocolate Pretzels (4 Pack)", 
        price: 10.99, 
        category: "Pretzel" 
    },
    { 
        id: 6, 
        name: "Strawberry Ice Cream", 
        price: 2.99, 
        category: "Ice Cream" 
    },
    {
        id: 7, 
        name: "Chocolate Macaroons (4 Pack)", 
        price: 9.99, 
        category: "Macaroon" 
    },
    {
        id: 8, 
        name: "Strawberry Pretzel", 
        price: 4.99, 
        category: "Pretzel" 
    },
    { 
        id: 9, 
        name: "Butter Pecan Ice Cream", 
        price: 2.99, 
        category: "Ice Cream" 
    },
    {
        id: 10, 
        name: "Rocky Road Ice Cream", 
        price: 2.99, 
        category: "Ice Cream"
    },
    {
        id: 11, 
        name: "Vanilla Macaroons (5 Pack)", 
        price: 11.99, 
        category: "Macaroon"
    },
    {
        id: 12, 
        name: "Lemon Cupcakes (4 Pack)", 
        price: 12.99, 
        category: "Cupcake"
    }
];

//({ name, id, price, category}) is used for desestructuring the array products
products.forEach(({ name, id, price, category})=>{
    dessertCards.innerHTML += `
    <div class="dessert-card">
        <h2>${name}</h2>
        <p class="dessert-price">${price} $</p>
        <p class="product-category">Category: ${category}</p>
        <button id="${id}" class="btn add-to-cart-btn">Add to cart</button>
    </div>
    `;
});

/* In JavaScript, a class is like a blueprint for creating objects. It allows you to define a set of properties and methods, and instantiate (or create) new objects with those properties and methods. */

class ShoppingCart {
    /*Classes have a special constructor method, which is AUTOMATICALLY called when a new instance of the class is created.*/
    constructor() {
        /*The this keyword in JavaScript is used to refer to the current object. Depending on where this is used, what it references changes. In the case of a class, it refers to the instance of the object being constructed. You can use the this keyword to set the properties of the object being instantiated.*/ 
        this.items = [];
        this.total = 0;
        this.taxRate = 8.25;
    }

    addItem(id, products){
        const product = products.find((item)=>item.id === id);
        //desestructuring name and product that comes from product
        const {name, price} = product;
        this.items.push(product);
        const totalCountPerProduct = {};
        this.items.forEach((dessert)=>{
            //to prevent NaN resulting from undefined + 1, because dessert.id doesnt exist in the first attempt
            totalCountPerProduct[dessert.id] = (totalCountPerProduct[dessert.id] || 0) + 1;
        });
        const currentProductCount = totalCountPerProduct[product.id];
        const currentProductCountSpan = document.getElementById(`product-count-for-id${id}`);
        currentProductCount > 1 ? currentProductCountSpan.textContent = `${currentProductCount}x`
        : productsContainer.innerHTML += `
            <div id=dessert${id} class="product">
                <p>
                    <span class="product-count" id="product-count-for-id${id}">${name}</span>
                </p>
                <p>${price}</p>
            </div>
        `;
    };

    getCounts(){
        return this.items.length; 
    }

    clearCart(){
        if (!this.items.length){
            alert("Your shopping cart is already empty");
            return;
        }

        const isCartCleared = confirm(
            "Are you sure you want to clear all items from your shopping cart?"
        );

        if (isCartCleared) {
            this.items = [];
            this.total = 0;
            productsContainer.innerHTML = "";
            totalNumberOfItems.textContent = 0;
            cartSubTotal.textContent = 0;
            cartTaxes.textContent = 0;
            cartTotal.textContent = 0;
        }

    }

    calculateTaxes(amount){
        //toFixed will round the operation to two decimal points and return a string
        //to perform calculations use parseFloat to convert from string to float with the righ number of decimal places (2) in this case.
        return parseFloat(((this.taxRate / 100) * amount).toFixed(2));
    }

    calculateTotal(){
        const subTotal = this.items.reduce((total, item)=>total+item.price, 0);
        const tax = this.calculateTaxes(subTotal);
        this.total = subTotal + tax;
        cartSubTotal.textContent = `$${subTotal.toFixed(2)}`;
        cartTaxes.textContent = `$${tax.toFixed(2)}`;
        cartTotal.textContent = `$${this.total.toFixed(2)}`;
        return this.total;
    }
    
};

//instanciate a object of the class ShoppingCart
const cart = new ShoppingCart();
//const addToCartBtns = document.getElementsByClassName("add-to-cart-btn");
/*You need to iterate through the buttons in your addToCartBtns variable. However, .getElementsByClassName() returns a Collection, which does not have a forEach method. so: */
 
const addToCartBtns = document.getElementsByClassName("add-to-cart-btn");
//addToCartBtns are an array of nodes, and forEach do not work in this data types directly so wrap the elements of addToCartBtns in an array with [...addToCartBtns]

[...addToCartBtns].forEach(
    (btn)=>{btn.addEventListener('click', (event)=>{
        //id will be catched as string
        cart.addItem(Number(event.target.id), products);
        totalNumberOfItems.textContent = cart.getCounts();
        cart.calculateTotal();
    })}
);

cartBtn.addEventListener('click',()=>{
    isCartShowing = !isCartShowing;
    showHideCartSpan.textContent = isCartShowing ? 'Hide' : 'Show';
    cartContainer.style.display = isCartShowing ? "block" : "none";
});

//further work: study the context of this and the hoisting for better understanding in the use of bind()
clearCartBtn.addEventListener('click', cart.clearCart.bind(cart));