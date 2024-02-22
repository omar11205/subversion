const changeDue = document.getElementById('change-due');
const cash = parseFloat(document.getElementById('cash').value);

let price = 1.87;
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

document.getElementById('purchase-btn').addEventListener('click', function() {
  
  if (isNaN(cash)) {
    alert('Please enter a valid cash amount.');
    return;
  }
  
  if (cash < price) {
    alert('Customer does not have enough money to purchase the item');
  } else if (cash === price) {
    changeDue.textContent = "No change due - customer paid with exact cash";
  } 
});