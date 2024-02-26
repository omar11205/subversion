const tbody = document.getElementById("datatable-tbody");

const statsTableIds = ["hp", "attack", "defense", "special-attack", "special-defense", "speed"];
const baseTableNames = ["HP:", "Attack:", "Defense:", "Special Attack:", "Special Defense:", "Speed"];

const baseTbody = (ids, baseNames) => {
    for(let i = 0; i < baseNames.length; i++) {
        const row = document.createElement('tr');
        const idCell = document.createElement('td');
        const baseNameCell = document.createElement('td');
    
        // Set the names and create tds.ids
        idCell.id = ids[i];
        baseNameCell.textContent = baseNames[i];
    
        // Append cells to the row
        row.appendChild(baseNameCell);
        row.appendChild(idCell);
        
        // Append row to the tbody
        tbody.appendChild(row);
    }
};

baseTbody(statsTableIds, baseTableNames);

searchInput = document.getElementById("search-input");
searchButton = document.getElementById("search-button");
pokemonName = document.getElementById("pokemon-name");
pokemonID = document.getElementById("pokemon-id");
weight = document.getAnimations("weight");
height = document.getElementById("height");
types = document.getElementById("types");



