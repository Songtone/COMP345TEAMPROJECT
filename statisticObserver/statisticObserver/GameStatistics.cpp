#include "stdafx.h"
#include "GameStatistics.h"
#include "Player.h"
#include <iostream>
#include <string>

//CONCRETE OBSERVER
using namespace std;


GameStatistics::GameStatistics() {

};
GameStatistics::GameStatistics(Player* s) {
	//Upon instantiation, attaches itself to a GameStatistics
	_subject = s;
	_subject->Attach(this);
};
GameStatistics::~GameStatistics() {
	//Upon destruction, detachess itself from a GameStatistics
	_subject->Detach(this);
};
void GameStatistics::Update(int n,int p) {
	//called by notify() when state subeject changes
	display(n,p);
};
void GameStatistics::display(int n,int p) {
	while (totalCountriesEntered) {
		cout << "How many countries in total?" << endl;
		cin >> totalCountries;
		totalCountriesEntered = false;
	}
	if (n == 1) {
		
		cout << "How many countries do you want to give to Player " << n << endl;
		cin >> countriesOwnedPlayer1;
	}

	if (n == 1) {
		
		float player1WorldPercent = float(countriesOwnedPlayer1) / float (totalCountries);
		cout <<"number of countries owned " <<countriesOwnedPlayer1 << endl;

		cout << "World Dominance Percentage: " << player1WorldPercent << "%" << endl;
		int barStatsPlayer1 = int(player1WorldPercent * 100);
		cout << "[";
		for (int i = 0; i < barStatsPlayer1; i++) {
			
			cout << "|";
		}
		for (int i = 0; i < (100 - barStatsPlayer1); i++) {
			cout << " ";
		}
		cout << "]";
	}
	if (n == 2) {
		cout << "Player " << n << endl;
		float player2WorldPercent = float(countriesOwnedPlayer2) / float (totalCountries);
		cout << "World Dominance Percentage: " << player2WorldPercent << "%" << endl;
		int barStatsPlayer2 = int(player2WorldPercent * 100);
		cout << "[";
		for (int i = 0; i < int(player2WorldPercent * 100); i++) {

			cout << "|";
		}
		for (int i = 0; i < (100 - barStatsPlayer2); i++) {
			cout << " ";
		}
		cout << "]";
	}
	if (n == 3) {
		cout << "Player " << n << endl;
		float player3WorldPercent = float(countriesOwnedPlayer3) / float(totalCountries);
		cout << "World Dominance Percentage: " << player3WorldPercent << "%" << endl;
		int barStatsPlayer3 = int(player3WorldPercent * 100);
		cout << "[";
		for (int i = 0; i < int(player3WorldPercent * 100); i++) {

			cout << "|";
		}
		for (int i = 0; i < (100 - barStatsPlayer3); i++) {
			cout << " ";
		}
		cout << "]";
	}
	if (n == 4) {
		cout << "Player " << n << endl;
		float player3WorldPercent = float(countriesOwnedPlayer3) / float(totalCountries);
		cout << "World Dominance Percentage: " << player3WorldPercent << "%" << endl;
		int barStatsPlayer3 = int(player3WorldPercent * 100);
		cout << "[";
		for (int i = 0; i < int(player3WorldPercent * 100); i++) {

			cout << "|";
		}
		for (int i = 0; i < (100 - barStatsPlayer3); i++) {
			cout << " ";
		}
		cout << "]";
	}
	if (n == 5) {
		cout << "Player " << n << endl;
		float player3WorldPercent = float(countriesOwnedPlayer3) / float(totalCountries);
		cout << "World Dominance Percentage: " << player3WorldPercent << "%" << endl;
		int barStatsPlayer3 = int(player3WorldPercent * 100);
		cout << "[";
		for (int i = 0; i < int(player3WorldPercent * 100); i++) {

			cout << "|";
		}
		for (int i = 0; i < (100 - barStatsPlayer3); i++) {
			cout << " ";
		}
		cout << "]";
	}
	if (n == 6) {
		cout << "Player " << n << endl;
		float player3WorldPercent = float(countriesOwnedPlayer3) / float(totalCountries);
		cout << "World Dominance Percentage: " << player3WorldPercent << "%" << endl;
		int barStatsPlayer3 = int(player3WorldPercent * 100);
		cout << "[";
		for (int i = 0; i < int(player3WorldPercent * 100); i++) {

			cout << "|";
		}
		for (int i = 0; i < (100 - barStatsPlayer3); i++) {
			cout << " ";
		}
		cout << "]";
	}

	
};