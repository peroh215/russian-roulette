#include <Windows.h>
#include <time.h>
#include "russianroulette.h"

int PLAYER_AMNT = 2;
int CHAMBER_SIZE = 7;

void setGamemode() {
	short int choice;
	cout << "\nChoose a gamemode:\n[1] Classic | [2] 50/50\n\n> ";
	cin >> choice;

	if (choice == 1) {
		// Classic gamemode
		PLAYER_AMNT = 2;
		CHAMBER_SIZE = 7 - 1;
	}
	else if (choice == 2) {
		// 50/50 gamemode
		PLAYER_AMNT = 2;
		CHAMBER_SIZE = 2 - 1; 
	}
	else {
		cout << "\nInvalid choice\n"; 
		setGamemode(); // Restarts the function
	}
}

void printStats(int bullet_loc, int turn_num) {
	cout << "----- STATS -----\n" << "Bullet was in chamber " << bullet_loc << endl << "It took " << turn_num << " turns until the gun shot\n";
}

int roll() {
	return rand()% CHAMBER_SIZE + 1; // Generates random number (1 - 7)
}

void game() {
	bool gameOver = false;
	int turn = 0;
	unsigned int bulletLocation = roll();
	short int playerChoice;
	cout << "\n=== GAME STARTS ===\nGamemode: Classic\nThe chamber is rolled and the gun is given to the player\nThe gun has " << CHAMBER_SIZE << " chambers\n\n";

	setGamemode();

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
				cout << "The gun shoots and player dies, AI wins\n\n";
				printStats(bulletLocation, turn);
				gameOver = true;
			}
			else {
				cout << "But the gun doesn't shoot\n\n";
			}
		}
		else {
			// AI's turn
			cout << "AI pulls the trigger...\n";
			if (roll() == bulletLocation) {
				cout << "The gun shoots and AI dies, Player wins\n\n";
				printStats(bulletLocation, turn);
				gameOver = true;
			}
			else {
				cout << "But the gun doesn't shoot\n\n";
			}
		}

		turn++;
		Sleep(1000);
	}
}
