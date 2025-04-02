// Base URL for the API
const baseUrl = "http://localhost:8200/game";

// Start the game
function startGame() {
    fetch(`${baseUrl}/start`)
        .then(response => response.text())
        .then(data => alert(data))
        .catch(error => console.error("Error:", error));
}

// Add a player
function addPlayer() {
    const playerName = document.getElementById("playerName").value;
    if (!playerName) {
        alert("Please enter a player name.");
        return;
    }
    fetch(`${baseUrl}/addPlayer/${playerName}`)
        .then(response => response.text())
        .then(data => alert(data))
        .catch(error => console.error("Error:", error));
}

// Player hits
function hit() {
    const playerName = document.getElementById("playerName").value;
    if (!playerName) {
        alert("Please enter a player name.");
        return;
    }

    fetch(`${baseUrl}/hit/${playerName}`)
        .then(response => response.json())
        .then(data => {
            // Find the player's hand value from the response
            const player = data.players.find(player => player.name === playerName);
            if (player) {
                const playerHandValue = player.handValue;

                // Check if the player busted
                if (playerHandValue > 21) {
                    alert(`You busted! Your hand value is ${playerHandValue}.`);
                } else {
                    alert(`Your hand value is ${playerHandValue}.`);
                }
            }

            // Update the game state on the UI
            displayGameState(data);
        })
        .catch(error => console.error("Error:", error));
}

// Player stands
function stand() {
    const playerName = document.getElementById("playerName").value;
    if (!playerName) {
        alert("Please enter a player name.");
        return;
    }
    fetch(`${baseUrl}/stand/${playerName}`)
        .then(response => response.text())
        .then(data => alert(data))
        .catch(error => console.error("Error:", error));
}

// Get player state
function getGameState() {
    fetch(`${baseUrl}/gameState`)
        .then(response => response.json())
        .then(data => displayGameState(data))
        .catch(error => console.error("Error:", error));
}

// Display game state in the <pre> element
function displayGameState(data) {
    const playerHandElement = document.getElementById("player-hand");
    const dealerHandElement = document.getElementById("dealer-hand");

    // Clear previous hands
    playerHandElement.innerHTML = "";
    dealerHandElement.innerHTML = "";

    // Display player hands
    if (data.players) {
        data.players.forEach(player => {
            const playerName = document.createElement("h3");
            playerName.textContent = `Player: ${player.name}`;
            playerHandElement.appendChild(playerName);

            player.hand.forEach(card => {
                const cardImage = document.createElement("img");
                const cardFileName = `${card.rank}_of_${card.suit}.png`; // Example: "Eight_of_Diamonds.png"
                cardImage.src = `cards/${cardFileName}`;
                cardImage.alt = `${card.rank} of ${card.suit}`;
                playerHandElement.appendChild(cardImage);
            });
        });
    }

    // Display dealer hand
    if (data.dealer) {
        const dealerName = document.createElement("h3");

        data.dealer.hand.forEach(card => {
            const cardImage = document.createElement("img");
            const cardFileName = `${card.rank}_of_${card.suit}.png`;
            cardImage.src = `cards/${cardFileName}`;
            cardImage.alt = `${card.rank} of ${card.suit}`;
            dealerHandElement.appendChild(cardImage);
        });
    }
}

function dealerTurn() {
    fetch(`${baseUrl}/dealerTurn`)
        .then(response => response.text())
        .then(data => {alert(data); displayGameState(data);})
        .catch(error => console.error("Error:", error));
}

function dealGame() {
    fetch(`${baseUrl}/deal`)
        .then(response => response.json())
        .then(data => displayGameState(data))
        .catch(error => console.error("Error:", error));
}
