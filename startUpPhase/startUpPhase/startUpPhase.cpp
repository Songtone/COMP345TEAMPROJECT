
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
	int countrySize;
	int n;
	int countryCount = 0;
	int countryNumber;
	int playerCount = 0;
	int totalArmiesToBePlaced = 0;

	bool initialArmyPlacement = true;
	bool goodCountryToPlaceArmy = true;

	string playerName;

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
		cout << "\n";
		cout << "Turn Order" << endl;//show the turn order for the game
		for (int i = 0; i < n; i++) {
			cout << player[i].getName() << endl;
		}
	}
	system("pause");
	cout << "\n";
	cout << "Here is the list of countries to be distributed among players." << endl;//assigning countries at random
	for (int i = 0; i < 18; i++) {
		cout << country[i].getCountryName() << endl;
	}
	system("pause");

	for (int i = 0; i < 18; i++) {//to randomaize the countries
		country[i].setCountryRandoRoll(rand() % 20 + 1);
	}
	for (int i = 0; i < 18 - 1; i++) {//bubble sort to sort the countries for randomization
		for (int j = 0; j < 18 - i - 1; j++) {
			if (country[j].getCountryRandoRoll() < country[j + 1].getCountryRandoRoll()) {
				countries temp = country[j];
				country[j] = country[j + 1];
				country[j + 1] = temp;
			}
		}
	}
	cout << "\nWill assign the countries to players in turn order!" << "\n" << endl;

	for (int i = 0; i < 18; i++) {//assigning countries randomly to players
		for (int j = 0; j < n; j++) {
			if (countryCount < 18) {
				cout << player[j].getName() << " received " << country[countryCount].getCountryName() << endl;
				country[countryCount].setOwner(player[j].getName());
				player[j].setNumberOfCountriesOwned(player[j].getNumberOfCountriesOwned() + 1);// could show the name of the country
				countryCount++;
			}
		}
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {//display how many countries each player received
		cout << player[i].getName() << " received " << player[i].getNumberOfCountriesOwned() << " countries" << endl;
	}
	cout << "\n";
	system("pause");
	//giving out the number of initial army for each player depending on the amount of players
	cout << "Giving out armies to players in round-robin fashion" << endl;
	cout << "\n";
	if (numberOfPlayers == 2) {

		for (int i = 0; i < n; i++) {
			player[i].setArmiesToPlace(40);
			player[i].setArmySize(40);
			cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << " armies" << endl;
		}
	}
	else if (numberOfPlayers == 3) {

		for (int i = 0; i < n; i++) {
			player[i].setArmiesToPlace(35);
			player[i].setArmySize(35);
			cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << " armies" << endl;
		}
	}
	else if (numberOfPlayers == 4) {

		for (int i = 0; i < n; i++) {
			player[i].setArmiesToPlace(30);
			player[i].setArmySize(30);
			cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << " armies" << endl;
		}
	}
	else if (numberOfPlayers == 5) {

		for (int i = 0; i < n; i++) {
			player[i].setArmiesToPlace(25);
			player[i].setArmySize(25);
			cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << " armies" << endl;
		}
	}
	else if (numberOfPlayers == 6) {

		for (int i = 0; i < n; i++) {
			player[i].setArmiesToPlace(20);
			player[i].setArmySize(20);
			cout << player[i].getName() << " received " << player[i].getArmiesToPlace() << " armies" << endl;
		}
	}
	cout << "\n";
	system("pause");
	cout << "Time to place the armies on your countries." << endl;
	cout << "1 army will be placed on every country from its owner." << endl;
	for (int i = 0; i < n; i++) {//placing one army on the countries the players own
		for (int j = 0; j < 18; j++) {
			if (player[i].getName() == country[j].getOwner()) {
				player[i].setArmiesToPlace(player[i].getArmiesToPlace() - 1);
				country[j].setArmyOnCountry(1);
			}
		}
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		totalArmiesToBePlaced += player[i].getArmiesToPlace();
	}
	for (int i = 0; i < totalArmiesToBePlaced / n + n; i++) {//loop to make sure we do every player until all armies are on the board
		for (int j = 0; j < n; j++) {
			if (player[j].getArmiesToPlace() > 0) {//will only go in if the player has more than 0 armies to be placed
				cout << "Player: " << player[j].getName() << endl;
				cout << "Armies left to place: " << player[j].getArmiesToPlace() << endl;
				cout << "Country Number | Country Name | Army Count" << endl;
				for (int k = 0; k < 18; k++) {
					if (country[k].getOwner() == player[j].getName()) {//display the country the current player owns
						cout << k << ". " << country[k].getCountryName() << ": " << country[k].getArmyOnCountry() << endl;
					}
				}
				cout << "\n";
				while (goodCountryToPlaceArmy) {//loop in case an invalid coutry is selected
					cout << player[j].getName() << " please enter the number of the country you wish to place your army on." << endl;
					cin >> countryNumber;
					if (player[j].getName() == country[countryNumber].getOwner()) {//making sure the player picks a country he owns
						player[j].setArmiesToPlace(player[j].getArmiesToPlace() - 1);//remove one army from the player pool
						country[countryNumber].setArmyOnCountry(country[countryNumber].getArmyOnCountry() + 1);
						goodCountryToPlaceArmy = false;
					}
					else {
						cout << "You don't own this country, please choose a country you own." << endl;
					}
				}
			}
			goodCountryToPlaceArmy = true;
		}
	}
	cout << "\nAll armies have been placed." << endl;
	cout << "\n";
	for (int i = 0; i < n; i++) {//asks the player if he wants to see his information, should be placed in game play loop
		showInfo = true;
		playerCount = i;
		while (showInfo) {
			cout << "Do you want to see your information " << player[i].getName() << "?" << endl;
			cout << "Y/N" << endl;
			cin >> answer;
			cout << "\n";
			if (answer == "Y" || answer == "y") {
				player[i].getName();
				cout << "Army to place " << player[i].getArmiesToPlace() << endl;
				cout << "Army size: " << player[i].getArmySize() << endl;
				cout << "Number of Countries Owned: " << player[i].getNumberOfCountriesOwned() << endl;
				cout << "Here is a list of countries you own with the army size on it: " << endl;
				cout << "\n";
				for (int i = 0; i < 18; i++) {
					if (country[i].getOwner() == player[playerCount].getName()) {
						cout << country[i].getCountryName() << ": " << country[i].getArmyOnCountry() << endl;
					}
				}
				cout << "\n";
				showInfo = false;
			}
			else if (answer == "N" || answer == "n") {
				cout << "Continue" << endl;
				cout << "\n";
				showInfo = false;
			}
			else {
				cout << "Invalid response, please try again! \n" << endl;
				cout << "\n";
			}
		}
	}
}