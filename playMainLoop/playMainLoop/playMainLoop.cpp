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

	countries *country;
	country = new countries[18];
	//generating countries
	country[0].setCountryName("Ireland");
	country[1].setCountryName("Chile");
	country[2].setCountryName("Vietnam");
	country[3].setCountryName("South Korea");
	country[4].setCountryName("Canada");
	country[5].setCountryName("Japan");
	country[6].setCountryName("Israel");
	country[7].setCountryName("Mauritius");
	country[8].setCountryName("England");
	country[9].setCountryName("Finland");
	country[10].setCountryName("Serbia");
	country[11].setCountryName("Iraq");
	country[12].setCountryName("Lebanon");
	country[13].setCountryName("Bahamas");
	country[14].setCountryName("Cuba");
	country[15].setCountryName("Algeria");
	country[16].setCountryName("Russia");
	country[17].setCountryName("China");

	while (turnOrder) {//determining the turn order. we can put the players in an array.
		for (int i = 0; i < n; i++) {
			cout << "Player " << i + 1 << ", enter your name!" << endl;
			cin >> playerName;
			player[i].setName(playerName);
			turnOrder = false;
		}
	}
	cout << "\n";
	while (noWinner) {
		for (int i = 0; i < n; i++) {
			phases = true;
			while (phases) {
				cout << "Player " << player[i].getName() << endl;
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
					for (int i = 0; i < 18; i++) {//set all countries to one player
						country[i].setOwner(player[0].getName());
						cout << country[i].getCountryName() << " Owned By: " << country[i].getOwner() << endl;
					}
					
						for (int i = 0; i < 17; i++) {
							if (country[i].getOwner() == country[i + 1].getOwner()) {
								ownAllCountries = true;
							}
						}

					if (ownAllCountries) {
						cout << " WE HAVE A WINNER " << endl;
						noWinner = false;
						phases = false;
					}
					break;

				case 3: cout << "Fortification Initiated!" << endl;
					cout << "Fortification Function should be here" << endl;
					cout << "\n";
					phases = false;
					break;
				}

			}
		}
	}
	}



