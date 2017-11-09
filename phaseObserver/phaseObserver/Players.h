#pragma once
#include "stdafx.h"
#include "Subject.h"

class Players : public Subject {
public:
	Players();
	int getPhase() { return phase; }
	
	void startPlayers(int n);
	void reinforce(int n);
	void attack(int n);
	void fortification(int n);
	~Players();
private:
	int phase;
	//int hour;
	//int minute;
	//int second;
};
