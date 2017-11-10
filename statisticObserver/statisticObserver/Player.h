#pragma once
#include "Subject.h"
#include <vector>

class Player : public Subject {
public:

	Player();
	~Player();
	void showGameStats(int n,int p);
	void showStats(int n, int p);
};