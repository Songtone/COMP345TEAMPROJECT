
#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int numPlay;
int numberOfCountries;
int numberOfCountriesAssigned;
int numberOfCountriesOwned;
bool playerNumber = true;
bool turnOrder = true;
void startUp(int numberOfPlayers);


class players {
	int rolled;
	int army;
	int countriesOwned;
	string name;
public:
	void playerRoll(int roll) {//the players roll for the turn order
		rolled = roll;
	}
	int getPlayerRoll() { return rolled; }
	void setName(string s) {//set the names of the players
		name = s;
	}
	string getName() { return name; }
	void setArmiesToPlace(int a) {
		army = a;
	}
	int getArmiesToPlace() { return army; }
	void setNumberOfCountriesOwned(int c) {
		countriesOwned = c;
	}
	int getNumberOfCountriesOwned() { return countriesOwned; }
	players() : rolled(0),army(0),name("Player 0"),countriesOwned(0) {}//default constructor
	
	players(const players& p)//copy constructor
	{
		name = p.name;
		rolled = p.rolled;
		army = p.army;
		countriesOwned = p.countriesOwned;
	}
};
int main()
{
	while (playerNumber) {//loop for the start up function
		cout << "How many players?" << endl;
		cin >> numPlay;
		if (numPlay < 2 || numPlay > 6) {
			cout << "Invalid number of players!" << endl;
			cout << "Please try again!" << endl;
		}
		else {
			startUp(numPlay);
			playerNumber = false;
		}
	}
	system("pause");
	return 0;
}

void startUp(int numberOfPlayers) {
	srand(time(NULL));
	int n;
	string playerName;
	
		players *player;
		player = new players[numberOfPlayers];
		n = numberOfPlayers;
		while (turnOrder) {//determining the turn order. we can put the players in an array.
			for (int i = 0; i < n; i++) {
				cout << "Player " << i+1 << ", enter your name!" << endl;
				cin >> playerName;
				player[i].setName(playerName);
				
				turnOrder = false;
			}
			for (int i = 0; i < n; i++) {
				player[i].playerRoll(rand() % 6 + 1);
				cout << player[i].getName() << " Rolled: " << player[i].getPlayerRoll() << "\n" << endl;
			}
			for (int i = 0; i < n - 1; i++) {//bubble sort
				for (int j = 0; j < n - i - 1; j++) {
					if (player[j].getPlayerRoll() < player[j + 1].getPlayerRoll()) {
						players temp = player[j];
						player[j] = player[j + 1];
						player[j + 1] = temp;
					}
				}
			}
			cout << "Turn Order" << endl;
			for (int i = 0; i < n; i++) {
				cout << player[i].getName() << endl;
			}
		}
		cout << "\nHow many countries are there?" << endl;//assigning countries at random
		cin >> numberOfCountries;
		numberOfCountriesAssigned = numberOfCountries / numberOfPlayers;
		cout << "Will assign the countries to players in turn order!" << "\n" << endl;
		for (int i = 0; i < numberOfCountries / numberOfPlayers;i++) {
			for (int j = 0; j < n; j++) {
				player[j].setNumberOfCountriesOwned(player[j].getNumberOfCountriesOwned() + 1);// could show the name of the country
			}
		}
		
		for (int i = 0; i < n; i++) {//display how many countries each player received
			cout << player[i].getName() << " received " << player[i].getNumberOfCountriesOwned() << " countries" << endl;
		}

		cout << "\n"<< endl;
		//giving out the number of initial army for each player depending on the amount of players
		if (numberOfPlayers == 2) {
			
			for (int i = 0; i < n; i++) {
				player[i].setArmiesToPlace(40);
				cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << endl;
			}
		}
		else if (numberOfPlayers == 3) {
			
			for (int i = 0; i < n; i++) {
				player[i].setArmiesToPlace(35);
				cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << endl;
			}
		}
		else if (numberOfPlayers == 4) {
			
			for (int i = 0; i < n; i++) {
				player[i].setArmiesToPlace(30);
				cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << endl;
			}
		}
		else if (numberOfPlayers == 5) {
			
			for (int i = 0; i < n; i++) {
				player[i].setArmiesToPlace(25);
				cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << endl;
			}
		}
		else if (numberOfPlayers == 6) {
			
			for (int i = 0; i < n; i++) {
				player[i].setArmiesToPlace(20);
				cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << endl;
			}
		}
}


