var data = [
    {
        id: 0,
        img: 'cart-img/food2-removebg-preview.png',
        name: 'Afang soup',
        price: 700,
        quantity: 1,
        itemInCart: false
    },
    {
        id: 1,
        img: 'cart-img/food5-removebg-preview.png',
        name: 'Chicken soup',
        price: 1500,
        quantity: 1
    },
    {
        id: 2,
        img: 'cart-img/food4-removebg-preview.png',
        name: 'Spaghetti',
        price: 500,
        quantity: 1
    },
    {
        id: 3,
        img: 'cart-img/food6-removebg-preview.png',
        name: 'Egg Sauce with yam',
        price: 1000,
        quantity: 1
    },
    {
        id: 4,
        img: 'cart-img/food3-removebg-preview.png',
        name: 'Coconut Rice',
        price: 1400,
        quantity: 1
    },
    {
        id: 5,
        img: 'cart-img/food1-removebg-preview.png',
        name: 'Abasha',
        price: 500,
        quantity: 1
    },
    {
        id: 6,
        img: 'cart-img/food2-removebg-preview.png',
        name: 'Bitter Leaf soup',
        price: 800,
        quantity: 1
    },
    {
        id: 7,
        img: 'cart-img/food5-removebg-preview.png',
        name: 'Jolly Rice',
        price: 1400,
        quantity: 1
    },
];

// Latest Food
data.forEach(item => {
    document.getElementById('card').innerHTML+= `
    <div class="item-container" id="0">
    <div class="card-item">
        <img src="${item.img}" alt="food" id="card-img">
        <p id="item-name">${item.name}</p>
        <div id="add-to-cart" addToCart(${item.id})>Add</div>
        <i id="add-to-cart" class="fa fa-shopping-cart" onclick='addToCart(${item.id})'></i>
        <h3 id="item-price">Price : &#8358; ${item.price}</h3>
    </div>
    </div>
    `;
})


// New Food
data.forEach(item => {
    document.getElementById('new').innerHTML += `
    <div class="item-container" id="0">
    <div class="card-item">
        <img src="${item.img}" alt="food" id="card-img">
        <p id="item-name">${item.name}</p>
        <div id="add-to-cart" addToCart(${item.id})>Add</div>
        <i id="add-to-cart" class="fa fa-shopping-cart" onclick='addToCart(${item.id})'></i>
        <h3 id="item-price">Price : &#8358; ${item.price}</h3>
    </div>
</div>
    `;
})

// Array to store cart lists
let cartArray = [];
var toggleCart = false;
var clrNode = document.getElementById('item-body');
// Toggle cart
function cart() {
    toggleCart = !toggleCart
    toggleCartfunc();
}  //click event to display cart

// Hide Cart
function home() {
    toggleCart = false;
    toggleCartfunc();
};

// Checks Cart
function toggleCartfunc() {
  showCartDetails()
  totalSummary();
  if(toggleCart) {
    document.getElementById('main').style.display = 'none';
    // document.getElementById('details-page').style.display = 'none';
    document.getElementById('cart-container').style.display = 'block';
  } else {
    document.getElementById('main').style.display = 'block';
    document.getElementById('cart-container').style.display = 'none';
  }
}

//add items to the cart
function addToCart(id){
    let addItem;
    data.forEach((item, i) => {

        if (item.id == id) {
          addItem = item;
        }
      });
      for (let j = 0; j < cartArray.length; j++) {
        if(cartArray[j].id == addItem.id) {
          return alert('Your item is already there');
        }
      }
    cartArray.push(addItem);
    alert('Item added to your cart');
    console.log(cartArray);
    showCartDetails()
}

function showCartDetails() {
  totalSummary();
  if(cartArray.length == 0) {
    document.getElementById('cart-itself').innerHTML = '<div style="padding: 50px; text-align:center;">Your Cart Is Empty</div>';
  } else {
    document.getElementById('cart-itself').innerHTML = `<div class="cart-list">
    <div>Picture</div>
    <div>Name</div>
    <div>Quantity</div>
    <div>Increase/Decrease Button</div>
    <div>Price Per Item</div>
    <div>Total Item(s) Price</div>
    </div>`;
    cartArray.forEach((cartItem, i) => {
      document.getElementById('cart-itself').innerHTML +=  `<div class="cart-list">
      <img id="listImg" src="${cartItem.img}" style="width: 100px; width: 100px;" />
      <h3 class="list-name">${cartItem.name}</h3>
      <h3 class="quantity">${cartItem.quantity}</h3>
      <div><button onclick="changeQuantity(${cartItem.id}, 'sub', ${cartItem.quantity})" style="padding: 5px; border: none; background-color: blue;"> - </button> <button onclick="changeQuantity(${cartItem.id}, 'add')" style="padding: 5px; border: none; background-color: blue;"> + </button></div>
      <h3 class="pay">${cartItem.price}</h3>
      <h3>${cartItem.price * cartItem.quantity}</h3>
      <button style="height: 40px;" onclick="deleteItem(${cartItem.id})">Delete</button>
      </div>`;
    });
  }
}

function changeQuantity(id, value, quantity) {
  if(quantity -1 <= 0) {
    alert("Negative values are not acceptable");
  } else {
    if(value == 'add') {
      for (let j = 0; j < cartArray.length; j++) {
        if(cartArray[j].id == id) {
          cartArray[j].quantity++;
        }
      }
    } else if (value == 'sub') {
      for (let j = 0; j < cartArray.length; j++) {
        if(cartArray[j].id == id) {
          cartArray[j].quantity--;
        }
      }
    }

  }
  showCartDetails();
}

function deleteItem(id) {
  for (let j = 0; j < cartArray.length; j++) {
    if(cartArray[j].id == id) {
      // cartArray.splice(cartArray[j], 1);
      cartArray.splice(cartArray.indexOf(cartArray[j]), 1);
    }
  }
  showCartDetails()
}

function totalSummary() {
  let totalPrice = 0;
  let quantity = 0;
  for (let j = 0; j < cartArray.length; j++) {
    totalPrice += cartArray[j].price * cartArray[j].quantity;
    quantity += cartArray[j].quantity;
  }
  document.getElementById('total').innerHTML = `<h3 id="total-items">Quantity: ${quantity}</h3>
  <h2>Amount: ${totalPrice}</h2>`;
}
