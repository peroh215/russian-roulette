#ifndef RUSSIANROULETTE_H
#define RUSSIANROULETTE_H

#include <iostream>
using namespace std;

inline int CHAMBER_SIZE(int _SIZE=7) { int CS = _SIZE - 1; return CS; }
void game();
void options();
#endif
