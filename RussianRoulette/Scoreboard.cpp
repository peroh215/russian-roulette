#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "russianroulette.h"
#include "text-table.h"

struct Score {
	std::string username;
	int wins;
	int losses;
};

int GAMES_WON;
int GAMES_LOST;
std::list<Score> scores;

void saveScore(char name[30], int gamesWon, int gamesLost) {
	// Saves score to scoreboard file
	ofstream scoreFile;
	scoreFile.open("score.roulette", std::ios::app);
	if (scoreFile.is_open()) {
		scoreFile << name << ":" << gamesWon << ":" << gamesLost << endl; // Example: "Jeff:6:10"
		scoreFile.close();
		cout << "Score saved!\n";
	}
	else { cout << "ERROR: Unable to open file"; }
	return;
}

void loadScore() {
	// Loads scores from scoreboard file
	ifstream scoreFile;
	TextTable t( '-', '|', '+' );
	scoreFile.open("score.roulette", std::ios::in);
	//cout << "\n#### NAME # WINS # LOSSES ####\n";
	if (scoreFile.is_open()) {
		std::string line;
		std::vector<std::string> results;
		int e; // For table formatting, ends row for every 3 results item

		while (scoreFile >> line) {
			boost::split(results, line, [](char c) {return c == ':'; });
			e = 0;
			for (auto i : results) {
				t.add(i);
				e++;
				if (e == 3) {
					t.endOfRow();
				}
			}
			t.setAlignment(2, TextTable::Alignment::RIGHT);
		}
		scoreFile.close();
		cout << t;
	}
}

void askScore() {
	// Asks if you want to save score
	char input;
	cout << "\nSave score? [Y/N] ";
	cin >> input;

	if (tolower(input) == 'y') {
		char name[20];
		cout << "\nName: ";
		cin >> name;
		saveScore(name, ::GAMES_WON, ::GAMES_LOST);
	}
	else if (tolower(input) == 'n') { ; }
	else { cout << "ERROR: Invalid input, you can only enter Y(es) or N(o)"; }
	input = NULL;
	return;
}
