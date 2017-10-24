
#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int numPlay;
int numberOfCountriesAssigned;
int numberOfCountries;

bool playerNumber = true;
bool turnOrder = true;
bool showInfo;

string answer;

void startUp(int numberOfPlayers);


class players {
	
public:
	int rolled;
	int army;
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

	void setArmiesToPlace(int a) {
		army = a;
	}
	int getArmiesToPlace() { return army; }

	void setNumberOfCountriesOwned(int c) {
		numberOfCountriesOwned = c;
	}
	int getNumberOfCountriesOwned() { return numberOfCountriesOwned; }

	players() : rolled(0),army(0),name("Player 0"), numberOfCountriesOwned(0) {}//default constructor
	
	players(const players& p)//copy constructor
	{
		name = p.name;
		rolled = p.rolled;
		army = p.army;
		numberOfCountriesOwned = p.numberOfCountriesOwned;
	}

	void showPlayerInformation() {//show information of player
		cout << "Countries: " << "Put a list of countries this player owns." << endl;
		cout << "Total Armies: " << "Put total armies here" << endl;
		
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
				player[i].setPlayerTurnOrderRoll(rand() % 6 + 1);
				cout << player[i].getName() << " Rolled: " << player[i].getPlayerTurnOrderRoll() << "\n" << endl;
			}
			for (int i = 0; i < n - 1; i++) {//bubble sort
				for (int j = 0; j < n - i - 1; j++) {
					if (player[j].getPlayerTurnOrderRoll() < player[j + 1].getPlayerTurnOrderRoll()) {
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
		for (int i = 0; i < n; i++) {//asks the player if he wants to see his information, should be placed in game play loop
			showInfo = true;
			while (showInfo) {
			cout << "Do you want to see your information " << player[i].getName() << "?" << endl;
			cout << "Y/N" << endl;
			cin >> answer;
			
				if (answer == "Y" || answer == "y") {
					player[i].showPlayerInformation();
					showInfo = false;
				}
				else if (answer == "N" || answer == "n") {
					cout << "Continue" << endl;
					showInfo = false;
				}
				else {
					cout << "Invalid response, please try again! \n" << endl;
				}
			}
		}
}


