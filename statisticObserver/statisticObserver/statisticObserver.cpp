#include "stdafx.h"
#include "GameStatistics.h"
#include "Player.h"
#include <iostream>
using namespace std;


int numberOfPlayers;

int main(void) {
	cout << "How many players?" << endl;
	cin >> numberOfPlayers;
	//create Player to be observed
	Player *player = new Player;

	GameStatistics *gameStatistics = new GameStatistics(player);

		for (int i = 0; i < numberOfPlayers; i++) {
			player->showGameStats(i + 1, numberOfPlayers);
			cout << endl;
		}
	
	
	system("pause");
	return 0;
}