
#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int numPlay;
int numberOfCountries;
int numberOfCountriesAssigned;
bool playerNumber = true;
bool turnOrder = true;
void startUp(int numberOfPlayers);


class players {
	int rolled;
	int army;
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
	int getArmies() { return army; }
	players() : rolled(0),army(0),name("Player 0") {}//default constructor
	players(const players& p)//copy constructor
	{
		name = p.name;
		rolled = p.rolled;
		army = p.army;
	}
};
int main()
{
	while (playerNumber) {
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
		cout << "Each player will receive " << numberOfCountriesAssigned << " countries at random.\n" << endl;


		//giving out the number of initial army for each player depending on the amount of players

		if (numberOfPlayers == 2) {
			cout << "Each player receives 40 armies. \n" << endl;
			for (int i = 0; i < n; i++) {
				player[i].setArmiesToPlace(40);
				cout << player[i].getName() << " received " << player[i].getArmies() << endl;
			}
		}
		else if (numberOfPlayers == 3) {
			cout << "Each player receives 35 armies.\n" << endl;
			for (int i = 0; i < n; i++) {
				player[i].setArmiesToPlace(35);
				cout << player[i].getName() << " received " << player[i].getArmies() << endl;
			}
		}
		else if (numberOfPlayers == 4) {
			cout << "Each player receives 30 armies.\n" << endl;
			for (int i = 0; i < n; i++) {
				player[i].setArmiesToPlace(30);
				cout << player[i].getName() << " received " << player[i].getArmies() << endl;
			}
		}
		else if (numberOfPlayers == 5) {
			cout << "Each player receives 25 armies.\n" << endl;
			for (int i = 0; i < n; i++) {
				player[i].setArmiesToPlace(25);
				cout << player[i].getName() << " received " << player[i].getArmies() << endl;
			}
		}
		else if (numberOfPlayers == 6) {
			cout << "Each player receives 20 armies.\n" << endl;
			for (int i = 0; i < n; i++) {
				player[i].setArmiesToPlace(20);
				cout << player[i].getName() << " received " << player[i].getArmies() << endl;
			}
		}
}


