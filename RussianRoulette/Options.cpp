#include "russianroulette.h"

int CHAMBER_SIZE = 7;

void changeOption(short int inp) {
	if (inp == 1) {
		cout << "Enter new chamber size: ";
		cin >> CHAMBER_SIZE;
	}
	else if (inp == 2) { return; }
	else { cout << "\nInvalid choice\n"; }
}

void options() {
	short int choice;
	cout << "\n===== OPTIONS =====\n[1] Chamber size (" << CHAMBER_SIZE << ")\n[2] Return\n\n> ";
	cin >> choice;
	changeOption(choice);
}
