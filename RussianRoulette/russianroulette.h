#ifndef RUSSIANROULETTE_H
#define RUSSIANROULETTE_H

#include <iostream>
using namespace std;

// Game
extern int CHAMBER_SIZE;
extern int PLAYER_AMNT;
void game();

// Scoreboard
extern int GAMES_WON;
extern int GAMES_LOST;
void saveScore();
void loadScore();
#endif
