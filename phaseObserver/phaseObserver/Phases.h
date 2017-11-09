#pragma once
#include "stdafx.h"
#include "Observer.h"
#include "Players.h"

class Phases : public Observer {
public:
	Phases();
	Phases(Players* s);
	~Phases();
	void Update(int n);
	void display(int n);
	bool attack = true;
	string confirm;
	bool winner = true;
	string countryToReinforce;
	string countryAttack;
	string countryDefense;
	string countryToReceiveFortify;
	string countryToGiveFortify;
	int numberOfArmiesToFortify;
	int numberOfAttackers;

private:
	Players* _subject;
};