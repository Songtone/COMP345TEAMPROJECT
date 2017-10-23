
#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

int numPlay;
bool turnOrder = true;
void startUp(int numberOfPlayers);

class players {
public:
	int playerRoll;
};

int main()
{
	
	cout <<"How many players?" << endl;
	cin >> numPlay;
	startUp(numPlay);
	system("pause");
	return 0;
}

void startUp(int numberOfPlayers) {
	srand(time(NULL));
	switch (numberOfPlayers) {
	case 2: 
		players player1;
		players player2;
		while (turnOrder) {//determining the turn order. we can put the players in an array.
			player1.playerRoll = rand() % 6 + 1;
			cout << "Player 1 Rolled: " << player1.playerRoll << endl;
			player2.playerRoll = rand() % 6 + 1;
			cout << "Player 2 Rolled: " << player2.playerRoll << endl;
			if (player1.playerRoll > player2.playerRoll) {
				cout << "Player 1 starts! Followed by Player 2" << endl;
				turnOrder = false;
			}
			else if(player1.playerRoll < player2.playerRoll) {
				cout << "Player 2 starts! Followed by Player 1" << endl;
				turnOrder = false;
			}
			else {
				cout << "It's a tie! Reroll!" << endl;
			}

		}
		break;
	/*case 3:
		players player1;
		players player2;
		players player3;
		break;
	case 4:
		players player1;
		players player2;
		players player3;
		players player4;
		break;
	case 5:
		players player1;
		players player2;
		players player3;
		players player4;
		players player5;
		break;
	case 6:
		players player1;
		players player2;
		players player3;
		players player4;
		players player5;
		players player6;
		break;*/
	}

}


