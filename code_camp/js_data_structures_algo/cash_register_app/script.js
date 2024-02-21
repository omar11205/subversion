document.getElementById('purchase-btn').addEventListener('click', function() {
    const cash = parseFloat(document.getElementById('cash').value);
    const price = 10; // Set your price here
  
    if (isNaN(cash)) {
      alert('Please enter a valid cash amount.');
      return;
    }
  
    if (cash < price) {
      alert('Customer does not have enough money to purchase the item.');
    } else if (cash === price) {
      document.getElementById('change-due').textContent = 'No change due - customer paid with exact cash';
    } else {
      var change = cash - price;
      document.getElementById('change-due').textContent = 'Change due: $' + change.toFixed(2);
    }
  });