
#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int numPlay;
bool turnOrder = true;
void startUp(int numberOfPlayers);

class players {
	int rolled;
public:
	void playerRoll(int roll) {
		rolled = roll;
	}
	int getPlayerRoll() { return rolled; }
	string p;
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
	int size;
	int n;
	switch (numberOfPlayers) {
	case 2: 
		players player[2+1];
		n = sizeof(player)/sizeof(player[0]) - 1;
		cout << "Size is " << n << endl;

		player[0].p = "Player 1";
		player[1].p = "Player 2";
		while (turnOrder) {//determining the turn order. we can put the players in an array.
			for (int i = 0; i < 2; i++) {
				player[i].playerRoll(rand() % 6 + 1);
				cout << player[i].p << " Rolled: " << player[i].getPlayerRoll() << endl;
				turnOrder = false;
			}
			/*for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					if (player[j].getPlayerRoll() > player[j + 1].getPlayerRoll()) {
						player[numberOfPlayers + 1] = player[j];
						player[j] = player[j + 1];
						player[j + 1] = player[numberOfPlayers + 1];

					}
				}
			}
			cout << "Turn Order" << endl;
			for (int i = 0; i < n - 1; i++) {
				cout << player[i].p << endl;
			}*/
				
			
			if (player[0].getPlayerRoll() > player[1].getPlayerRoll()) {
				cout << "Player 1 starts! Followed by Player 2" << endl;
				turnOrder = false;
			}
			else if(player[0].getPlayerRoll() < player[1].getPlayerRoll()) {
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


