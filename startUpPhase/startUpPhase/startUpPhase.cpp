
#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include "startUpPhase.h"
using namespace std;


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

	countries *country;
	country = new countries[18];
	country[0].setName("Ireland");
	country[1].setName("Chile");
	country[2].setName("Vietnam");
	country[3].setName("South Korea");
	country[4].setName("Canada");
	country[5].setName("Japan");
	country[6].setName("Israel");
	country[7].setName("Mauritius");
	country[8].setName("England");
	country[9].setName("Finland");
	country[10].setName("Serbia");
	country[11].setName("Iraq");
	country[12].setName("Lebanon");
	country[13].setName("Bahamas");
	country[14].setName("Cuba");
	country[15].setName("Algeria");
	country[16].setName("Russia");
	country[17].setName("China");
	country[18].setName("Sri Lanka");


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
		for (int i = 0; i < n; i++) {
			player[i].setPlayerTurnOrderRoll(rand() % 6 + 1);
			
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
		
		cout << "Turn Order" << endl;//show the turn order for the game
		for (int i = 0; i < n; i++) {
			cout << player[i].getName() << endl;
		}
	}
	cout << "\nHow many countries are there?" << endl;//assigning countries at random
	cin >> numberOfCountries;
	numberOfCountriesAssigned = numberOfCountries / numberOfPlayers;
	cout << "Will assign the countries to players in turn order!" << "\n" << endl;
	for (int i = 0; i < numberOfCountries / numberOfPlayers; i++) {
		for (int j = 0; j < n; j++) {
			player[j].setNumberOfCountriesOwned(player[j].getNumberOfCountriesOwned() + 1);// could show the name of the country
		}
	}

	for (int i = 0; i < n; i++) {//display how many countries each player received
		cout << player[i].getName() << " received " << player[i].getNumberOfCountriesOwned() << " countries" << endl;
	}

	cout << "\n" << endl;
	//giving out the number of initial army for each player depending on the amount of players
	cout << "Giving out armies to players in round" << endl;
	if (numberOfPlayers == 2) {

		for (int i = 0; i < n; i++) {
			player[i].setArmiesToPlace(40);
			cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << " armies" << endl;
		}
	}
	else if (numberOfPlayers == 3) {

		for (int i = 0; i < n; i++) {
			player[i].setArmiesToPlace(35);
			cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << " armies" << endl;
		}
	}
	else if (numberOfPlayers == 4) {

		for (int i = 0; i < n; i++) {
			player[i].setArmiesToPlace(30);
			cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << " armies" << endl;
		}
	}
	else if (numberOfPlayers == 5) {

		for (int i = 0; i < n; i++) {
			player[i].setArmiesToPlace(25);
			cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << " armies" << endl;
		}
	}
	else if (numberOfPlayers == 6) {

		for (int i = 0; i < n; i++) {
			player[i].setArmiesToPlace(20);
			cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << " armies"<< endl;
		}
	}
	cout << "\n" << endl;
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


