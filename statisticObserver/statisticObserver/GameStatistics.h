#pragma once
#include "Observer.h"
#include "Player.h"

class GameStatistics : public Observer {
public:
	GameStatistics();
	GameStatistics(Player* s);
	~GameStatistics();
	void Update(int n, int p);
	void display(int n,int p);	

	bool countriesGiven = true;
	bool totalCountriesEntered = true;
	int totalCountries;
	int countriesOwnedPlayer1;
	int countriesOwnedPlayer2;
	int countriesOwnedPlayer3;
	int countriesOwnedPlayer4;
	int countriesOwnedPlayer5;
	int countriesOwnedPlayer6;

private:
	Player* _subject;
};