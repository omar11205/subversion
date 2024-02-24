const changeDue = document.getElementById('change-due');
const cashEl = document.getElementById('cash');
const purchaseBtn = document.getElementById('purchase-btn');
const currentPricep = document.getElementById('price');

let price = 19.5;
currentPricep.innerText = `Current article price $${price}`;

let cid = [
  ["PENNY", 1.01],
  ["NICKEL", 2.05],
  ["DIME", 3.1],
  ["QUARTER", 4.25],
  ["ONE", 90],
  ["FIVE", 55],
  ["TEN", 20],
  ["TWENTY", 60],
  ["ONE HUNDRED", 100]
];

const checkCashRegister = (price, cash, cid) => {
  const UNIT_AMOUNT = {
    "PENNY": 0.01,
    "NICKEL": 0.05,
    "DIME": 0.10,
    "QUARTER": 0.25,
    "ONE": 1.00,
    "FIVE": 5.00,
    "TEN": 10.00,
    "TWENTY": 20.00,
    "ONE HUNDRED": 100.00
  }
  let totalCID = 0;
  for (let element of cid) {
    totalCID += element[1];
  }
  totalCID = totalCID.toFixed(2);
  let changeToGive = cash - price;
  const changeArray = [];
  if (changeToGive > totalCID) {
    return { status: "INSUFFICIENT_FUNDS", change: changeArray };
  } else if (changeToGive.toFixed(2) === totalCID) {
    return { status: "CLOSED", change: cid };
  } else {
    cid = cid.reverse();
    for (let elem of cid) {
      let temp = [elem[0], 0];
      while (changeToGive >= UNIT_AMOUNT[elem[0]] && elem[1] > 0) {
        temp[1] += UNIT_AMOUNT[elem[0]];
        elem[1] -= UNIT_AMOUNT[elem[0]];
        changeToGive -= UNIT_AMOUNT[elem[0]];
        changeToGive = changeToGive.toFixed(2);
      }
      if (temp[1] > 0) {
        changeArray.push(temp);
      }
    }
  }
  if (changeToGive > 0) {
    return { status: "INSUFFICIENT_FUNDS", change: [] };
  }
  return { status: "OPEN", change: changeArray};
}

const displayIterator = (element) => {
  changeDue.textContent += ` ${element[0]}: $${element[1]}`
};

purchaseBtn.addEventListener('click', function() {
  const cash = parseFloat(cashEl.value);
  if (isNaN(cash)) {
    alert('Please enter a valid cash amount.');
    return;
  }
  
  if (cash < price) {
    alert('Customer does not have enough money to purchase the item');
  } else if (cash === price) {
    changeDue.textContent = "No change due - customer paid with exact cash";
  } else if (cash > price){
    let objResult = checkCashRegister(price, cash, cid);
    if(objResult.status === "INSUFFICIENT_FUNDS"){
      changeDue.textContent = `Status: ${objResult.status}`;
    } else if (objResult.status === "CLOSED"){
      changeDue.textContent = `Status: ${objResult.status}`
      objResult.change.forEach(displayIterator);
    } else if (objResult.status === "OPEN"){
      changeDue.textContent = `Status: ${objResult.status}`
      objResult.change.forEach(displayIterator);
    }  
  }
});
