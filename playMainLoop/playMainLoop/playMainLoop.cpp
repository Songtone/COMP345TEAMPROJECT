// playMainLoop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "playMainLoop.h"
#include <iostream>
using namespace std;



int main() {
	while (playerNumber) {//loop for the start up function
		cout << "How many players?" << endl;
		cin >> numPlay;
		if (numPlay < 2 || numPlay > 6) {
			cout << "Invalid number of players!" << endl;
			cout << "Please try again!" << endl;
		}
		else {
			mainPlayerLoop(numPlay);
			playerNumber = false;
		}
	}
	system("pause");
	return 0;
}

void mainPlayerLoop(int numberOfPlayers) {
	string playerName;
	bool noWinner = true;
	bool ownAllCountries = false;
	bool phases = true;
	bool rF = true;
	int x;
	int n;
	players *player;
	player = new players[numberOfPlayers];
	n = numberOfPlayers;

	while (turnOrder) {//determining the turn order. we can put the players in an array.
		for (int i = 0; i < n; i++) {
			cout << "Player " << i + 1 << ", enter your name!" << endl;
			cin >> playerName;
			player[i].setName(playerName);
			turnOrder = false;
		}
	}
	while (noWinner) {
		for (int i = 0; i < n; i++) {
			cout << player[i].getName() << endl;
			while (phases) {

				cout << "Choose an option" << endl;
				cout << "1. Reinforce" << endl;
				cout << "2. Attack" << endl;
				cout << "3. Fortify \n" << endl;
				cin >> x;
				cout << endl;

				switch (x) {
				case 1: if (rF == true) {
					cout << "Reinforcement Initiated!" << endl;
					cout << "Reinforce function should be here. \n" << endl; // reinforcement() function here
					rF = false;
				}
						else if (rF == false) {
							cout << "Reinforcement can only be used once." << endl;
							cout << "Choose a valid option \n" << endl;
						}
						break;
				case 2: cout << "Attack Initiated!" << endl;
					cout << "Attack function should be here. \n" << endl; //attack() function should be here
					ownAllCountries = true;
					if (ownAllCountries) {
						cout << " WE HAVE A WINNER " << endl;
						noWinner = false;
						phases = false;
					}
					break;

				case 3: cout << "Fortification Initiated!" << endl;
					cout << "Fortification Function should be here" << endl;
					cout << "Next player function should be here" << endl;
					phases = false;
					break;
				}

			}
		}
	}
	}



