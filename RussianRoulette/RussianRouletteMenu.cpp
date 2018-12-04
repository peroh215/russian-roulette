#include <string>
#include "russianroulette.h"
using namespace std;

bool running = true;
static std::string help = "\n[1] Play game\n[2] Help\n[3] Exit";

void checkInput(int inp) {
	if (inp == 1) { 
		game(); // Start game
		cout << help;
	}
	else if (inp == 2) cout << help; // Help
	else if (inp == 3) exit(0); // Exit
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
