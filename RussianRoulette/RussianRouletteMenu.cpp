#include <string>
#include "russianroulette.h"
using namespace std;

bool running = true;
static std::string help = "\n[1] Play game\n[2] Save score\n[3] Load scores\n[4] Restart current score\n[5] Restart scoreboard\n[6] Help\n[7] Exit";

void checkInput(int inp) {	
	if (inp == 1) { game(); cout << help;} // Play game / Start game
	else if (inp == 2) askScore(); // Save score
	else if (inp == 3) loadScore(); // Load score
	else if (inp == 4) { ::GAMES_WON = 0; ::GAMES_LOST = 0; cout << "Current score was restarted\n"; } // Restart current RAM score
	else if (inp == 5) { remove("score.roulette"); cout << "Scoreboard was reseted\n\n"; }
	else if (inp == 6) cout << help; // Help
	else if (inp == 7) exit(0); // Exit
	else cout << "\nInvalid choice\n";
}

int main() {
	short int choice;
	cout << "========== RUSSIAN ROULETTE'S MAIN MENU ==========" << endl;
	cout << help;
	while (running == true) {
		cout << "\n> ";
		cin >> choice;
		checkInput(choice);
	}
	return 0;
}
