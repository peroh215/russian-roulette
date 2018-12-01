#include <Windows.h>
#include <time.h>
#include "russianroulette.h"

void printStats(int bullet_loc, int turn_num) {
	cout << "----- STATS -----\n" << "Bullet was in chamber " << bullet_loc << endl << "It took " << turn_num << " turns until the gun shot\n";
}

int roll() {
	return rand() % CHAMBER_SIZE() + 1;
}

void game() {
	bool gameOver = false;
	int turn = 0;
	unsigned int bulletLocation = roll();
	short int playerChoice;
	int triggerPresses;
	cout << "\n=== GAME STARTS ===\nThe chamber is rolled and the gun is given to the player\n";

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

		turn += 1;
		Sleep(1000);
	}
}
