#include <Windows.h>
#include <time.h>
#include <string>
#include "russianroulette.h"

int PLAYER_AMNT; // Player amount
int CHAMBER_SIZE; // Gun's chamber size
std::string gamemode; // For printing current gamemode

void createCustomGamemode() {
	int player_amount;
	int chamber_size;
	cout << "\n=== GAMEMODE CREATION ===\nPlayer amount: ";
	cin >> player_amount;
	cout << "Chamber size: ";
	cin >> chamber_size;
	::PLAYER_AMNT = player_amount;
	::CHAMBER_SIZE = chamber_size;
}

void setGamemode() {
	short int choice;
	cout << "\nChoose a gamemode:\n[1] Classic | [2] 50/50 | [3] 4 players | [4] Custom\n\n> ";
	cin >> choice;

	if (choice == 1) {
		// Classic gamemode
		gamemode = "Classic";
		PLAYER_AMNT = 2;
		CHAMBER_SIZE = 7 - 1;
	}
	else if (choice == 2) {
		// 50/50 gamemode
		gamemode = "50/50";
		PLAYER_AMNT = 2;
		CHAMBER_SIZE = 2 - 1; 
	}
	else if (choice == 3) {
		// 4 players
		gamemode = "4 players";
		PLAYER_AMNT = 4;
		CHAMBER_SIZE = 7 - 1;
	}
	else if (choice == 4) {
		// Custom gamemode
		gamemode = "Custom";
		createCustomGamemode();
	}
	else {
		cout << "\nInvalid choice\n"; 
		setGamemode(); // Restarts the function
	}
}

void printStats(int bullet_loc, int turn_num) {
	cout << "\n----- STATS -----\n" << "Bullet was in chamber " << bullet_loc << endl << "It took " << turn_num << " turns until the gun shot\n";
}

int roll() {
	return rand()% CHAMBER_SIZE + 1; // Generates random number (1 - 7)
}

void game() {

	setGamemode();

	bool gameOver = false;
	int turn = 0;
	short int playerChoice;
	int deadPlayers = 0;
	int playerAmount = ::PLAYER_AMNT; // Variable used to print player amount (Player amount - user)
	playerAmount--;

	unsigned int bulletLocation = roll();

	cout << "\n=== GAME STARTS ===\nGamemode: " << gamemode << "\nThe chamber is rolled and the gun is given to the player\nThere are " << playerAmount << " other player(s)\nThe gun has " << CHAMBER_SIZE << " chambers\n\n";

	while (gameOver == false) {
		srand(time(NULL));
		if ((turn % 2) == 0) {
			// Player's turn
			cout << "\n[1] Pull the trigger | [2] Give up\n> ";
			cin >> playerChoice;
			if (playerChoice == 1) { ; }
			else if (playerChoice == 2) { return; }
			else { cout << "Invalid choice, so you pull the trigger"; }

			cout << "\nPlayer pulls the trigger...\n";
			if (roll() == bulletLocation) {
				// Gun shoots
				cout << "The gun shoots and player dies, AI wins\n\n";
				printStats(bulletLocation, turn);
				gameOver = true;
			}
			else {
				// Gun doesn't shoot
				cout << "But the gun doesn't shoot\n\n";
			}
		}
		else {
			// AI's turn
			cout << playerAmount << " other player(s) pull the trigger...\n";
			for (int i = 1; i <= playerAmount; ++i) {
				if (roll() == bulletLocation) {
					// Gun shoots
					if ((playerAmount - 1) <= 0) {
						// Ends game if there is one player left
						printStats(bulletLocation, turn);
						gameOver = true;
					}
					else {
						// Continues game if there is more than 1 player alive
						PLAYER_AMNT--;
						deadPlayers++;
					}
				}
				else {
					// Gun doesn't shoot
					;
				}
			}
		}

		if (deadPlayers != 0) {
			cout << deadPlayers << " player(s) die(s)\nNow there are only " << playerAmount << " player(s) left\n";
		}
		else if (deadPlayers == 0 && (turn % 2) == 1 && gameOver == false) {
			cout << "But no one dies\n";
		}

		playerAmount -= deadPlayers;
		deadPlayers = 0;
		turn++;
		Sleep(500);
	}
}
