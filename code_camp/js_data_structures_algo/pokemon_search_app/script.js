const searchInput = document.getElementById("search-input");
const form = document.getElementById("form");
const searchButton = document.getElementById("search-button");
const pokemonName = document.getElementById("pokemon-name");
const pokemonID = document.getElementById("pokemon-id");
const weight = document.getElementById("weight");
const height = document.getElementById("height");
const typesCont = document.getElementById("types");
const tbody = document.getElementById("datatable-tbody");
const sprite = document.getElementById("img-sprite-container");
const pokeAPIURL = "https://pokeapi-proxy.freecodecamp.rocks/api/pokemon/";
const baseTableNames = ["HP:", "Attack:", "Defense:", "Special Attack:", "Special Defense:", "Speed:"];
const statsTableIds = ["hp", "attack", "defense", "special-attack", "special-defense", "speed"];

const statsSection = (ids, baseNames, data, status) => {
    tbody.innerHTML = "<tr><th>Base</th><th>Statistics</th></tr>";
    for(let i = 0; i < baseNames.length; i++) {
        const row = document.createElement('tr');
        const idCell = document.createElement('td');
        const baseNameCell = document.createElement('td');
        
        // Set the names and create tds.ids
        idCell.id = ids[i];
        if(status === "fill"){
            idCell.textContent = data.stats[i].base_stat;
        } else if (status === "clear"){
            idCell.textContent = '';
        }
        baseNameCell.textContent = baseNames[i];
        
        // Append cells to the row
        row.appendChild(baseNameCell);
        row.appendChild(idCell);
        
        // Append row to the tbody
        tbody.appendChild(row);
    }
};

statsSection(statsTableIds, baseTableNames, 0, "clear");

const stastIDS =(data)=>{
    const statsIDS = [];
    data.stats.forEach((statistics)=>{
        statsIDS.push(statistics.stat.name);
    })
    return statsIDS;
};

const frontSection = (data, status)=>{
    if(status === "fill"){
        pokemonName.textContent = `${data.name.toUpperCase()}`;
        pokemonID.textContent = `#${data.id}`;
        height.textContent = `Height: ${data.height}`;
        sprite.innerHTML = `<img id="sprite" src="${data.sprites.front_default}">`;
        weight.textContent = `Weight: ${data.weight}`;
        typesCont.innerHTML = data.types.map((obj)=>
            `<span class="${obj.type.name}">${obj.type.name}</span>`
        ).join('');
    } else if (status === "clear"){
        if (sprite){
            sprite.innerHTML = '';
        }
        typesCont.innerHTML = '';
        pokemonName.textContent = '';
        pokemonID.textContent = '';
        weight.textContent = '';
        height.textContent = '';
    }

}

const clearDisplay = () => {
    statsSection(statsTableIds, baseTableNames, 0, "clear");
    frontSection(0, "clear");
}

const pokeFetch = async () => {
    const pokeNameOrID = searchInput.value.toLowerCase().replace(/\s+/g, '-');
    try {
        const res = await fetch(`${pokeAPIURL}${pokeNameOrID}`);
        const data = await res.json();
        console.log(data);
        const statsIDCreated = stastIDS(data);
        statsSection(statsIDCreated, baseTableNames, data, "fill");
        frontSection(data, "fill");
        console.log(statsIDCreated);

    } catch (err) {
        alert('Pokémon not found');
        clearDisplay();
        console.log(`Pokémon not found: ${err}`);
    }
};

searchButton.addEventListener("click", ()=>{
    pokeFetch();
});













