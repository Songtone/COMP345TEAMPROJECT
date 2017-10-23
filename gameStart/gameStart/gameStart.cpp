// gameStart.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int playerNumber;
bool playerNumb = true;
void gameStart();

int main()
{
	gameStart();
	system("pause");
	return 0;
}
void gameStart() {
	cout << "WELCOME TO RISK!\n\n\n" << endl;
	cout << "Please select a map!" << endl;
	cout << "Map loader function here" << endl;//have a way to have the map loader choose the map here.

	while (playerNumb) {
		cout << "Please select a number of players! (2-6)" << endl;
		cin >> playerNumber;
		if (playerNumber <= 1 || playerNumber > 6) {
			cout << "Invalid number of players!" << endl;
			cout << "Please choose a number from 2 to 6!" << endl;
		}
		else {
			playerNumb = false;
			cout << "You have selected " << playerNumber << " players!" << endl;// create the players.

			switch (playerNumber) {//create the stuff for the players.
			case 2: cout << "Each player will receive 40 armies" << endl;
				cout << "Assign the players their own dice rolling faciities, assign each an empty card hand and create deck of cards." << endl;
				cout << "For " << playerNumber << " players." << endl;
				break;
			case 3: cout << "Each player will receive 35 armies" << endl;
				cout << "Assign the players their own dice rolling faciities, assign each an empty card hand and create deck of cards." << endl;
				cout << "For " << playerNumber << " players." << endl;
				break;
			case 4: cout << "Each player will receive 30 armies" << endl;
				cout << "Assign the players their own dice rolling faciities, assign each an empty card hand and create deck of cards." << endl;
				cout << "For " << playerNumber << " players." << endl;
				break;
			case 5: cout << "Each player will receive 25 armies" << endl;
				cout << "Assign the players their own dice rolling faciities, assign each an empty card hand and create deck of cards." << endl;
				cout << "For " << playerNumber << " players." << endl;
				break;
			case 6: cout << "Each player will receive 20 armies" << endl;
				cout << "Assign the players their own dice rolling faciities, assign each an empty card hand and create deck of cards." << endl;
				cout << "For " << playerNumber << " players." << endl;
				break;
			}
		}

	}


}

