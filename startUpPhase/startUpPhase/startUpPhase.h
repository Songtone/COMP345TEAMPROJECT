#ifndef STARTUPPHASE_H
#define STARTUPPHASE_H


#include <iostream>
#include <string>
using namespace std;

class players {//player class

public:
	int rolled;
	int armyToPlace;
	int armySize;
	int numberOfCountriesOwned;

	string name;

	void setPlayerTurnOrderRoll(int roll) {//the players roll for the turn order
		rolled = roll;
	}
	int getPlayerTurnOrderRoll() { return rolled; }

	void setName(string s) {//set the names of the players
		name = s;
	}
	string getName() { return name; }
	
	void setArmySize(int ar) {
		armySize = ar;
	}
	int getArmySize() { return armySize; }

	void setArmiesToPlace(int a) {
		armyToPlace = a;
	}
	int getArmiesToPlace() { return armyToPlace; }

	void setNumberOfCountriesOwned(int c) {
		numberOfCountriesOwned = c;
	}
	int getNumberOfCountriesOwned() { return numberOfCountriesOwned; }

	players() : rolled(0), armyToPlace(0), name("Player 0"), numberOfCountriesOwned(0) {}//default constructor

	players(const players& p)//copy constructor
	{
		name = p.name;
		rolled = p.rolled;
		armyToPlace = p.armyToPlace;
		numberOfCountriesOwned = p.numberOfCountriesOwned;
	}


};

class countries {//country class
public:
	
	string countryName;
	string owner;
	int armyOnCountry = 0;
	int countryRando;
	
	void setCountryRandoRoll(int rand) {
		countryRando = rand;
	}
	int getCountryRandoRoll() { return countryRando; }
	void setCountryName(string cName) {
		countryName = cName;
	}
	string getCountryName() { return countryName; }
	void setOwner(string id) {
		owner = id;
	}
	string getOwner() { return owner; }
	void setArmyOnCountry(int army) {
		armyOnCountry = army;
	}
	int getArmyOnCountry() { return armyOnCountry; }

	countries() : owner("default"), countryName("default"),armyOnCountry(0) {} // default constructor

	countries(const countries& c) {
		owner = c.owner;
		countryName = c.countryName;
		armyOnCountry = c.armyOnCountry;
	}
};

int tieCounter = 0;
int innerTieCount = 1;
int numPlay;
int numberOfCountriesAssigned;
int numberOfCountries;

bool playerNumber = true;
bool turnOrder = true;
bool showInfo;

string answer;

void startUp(int numberOfPlayers);




#endif STARTUPPHASE_H