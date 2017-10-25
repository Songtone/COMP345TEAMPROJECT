#ifndef STARTUPPHASE_H
#define STARTUPPHASE_H


#include <iostream>
#include <string>
using namespace std;

class players {//player class

public:
	int rolled;
	int army;
	int numberOfCountriesOwned;

	string name;
	string countryList[];

	void setPlayerTurnOrderRoll(int roll) {//the players roll for the turn order
		rolled = roll;
	}
	int getPlayerTurnOrderRoll() { return rolled; }

	void setName(string s) {//set the names of the players
		name = s;
	}
	string getName() { return name; }

	void setArmiesToPlace(int a) {
		army = a;
	}
	int getArmiesToPlace() { return army; }

	void setNumberOfCountriesOwned(int c) {
		numberOfCountriesOwned = c;
	}
	int getNumberOfCountriesOwned() { return numberOfCountriesOwned; }

	players() : rolled(0), army(0), name("Player 0"), numberOfCountriesOwned(0) {}//default constructor

	players(const players& p)//copy constructor
	{
		name = p.name;
		rolled = p.rolled;
		army = p.army;
		numberOfCountriesOwned = p.numberOfCountriesOwned;
	}

	void showPlayerInformation() {//show information of player
		cout << "Countries: " << "Put a list of countries this player owns." << endl;
		cout << "Total Armies: " << "Put total armies here\n" << endl;

	}
};

class countries {//country class
public:
	
	string name;
	string owner;
	int armyOnCountry = 0;

	void setName(string cName) {
		name = cName;
	}
	string getName() { return name; }
	void setOwner(string id) {
		owner = id;
	}
	string getOwner() { return owner; }
	void setArmyOnCountry(int army) {
		armyOnCountry = army;
	}
	int getArmyOnCountry() { return armyOnCountry; }

	countries() : owner("default"), name("default"),armyOnCountry(0) {} // default constructor

	countries(const countries& c) {
		owner = c.owner;
		name = c.name;
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