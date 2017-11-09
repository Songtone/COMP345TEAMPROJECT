#include "stdafx.h"
#include "Phases.h"
#include "Players.h"
#include <iostream>
using namespace std;

bool winner = true;
int numberOfPlayers;

int main(void) {
	cout << "How many players?" << endl;
	cin >> numberOfPlayers;
	//create playersto be observed
	Players *players = new Players;
	
	

	//create a phase that is connected to the players
	Phases *phases = new Phases(players);
	
	

	//Advancing the Phases updates the digital clock
	//as tick() calls Update() after it changed its state
	int count = 0;
	while (winner) {
		if (count < 5) {
			for (int i = 0; i < numberOfPlayers; i++) {
				players->startPlayers(i + 1);
				cout << "NEXT PLAYER \n" << endl;
			}
			count++;

		}
		else {
			winner = false;
		}
		
	}
	cout << "GAME OVER" << endl;
	system("pause");
	return 0;
}