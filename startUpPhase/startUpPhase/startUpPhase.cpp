
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
	string name;
public:
	void playerRoll(int roll) {
		rolled = roll;
	}
	int getPlayerRoll() { return rolled; }
	void setName(string s) {
		name = s;
	}
	string getName() { return name; }
	players() : rolled(0) {}
	players(const players& p)
	{
		name = p.name;
		rolled = p.rolled;
	}
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
	int n;
	
		players *player;
		player = new players[numberOfPlayers];
		n = numberOfPlayers;
		cout << "Size is " << n << endl;

		player[0].setName("Player 1");
		player[1].setName("Player 2");
		while (turnOrder) {//determining the turn order. we can put the players in an array.
			for (int i = 0; i < n; i++) {
				player[i].playerRoll(rand() % 6 + 1);
				cout << player[i].getName() << " Rolled: " << player[i].getPlayerRoll() << endl;
				turnOrder = false;
			}
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					if (player[j].getPlayerRoll() < player[j + 1].getPlayerRoll()) {
						players temp = player[j];
						player[j] = player[j + 1];
						player[j + 1] = temp;
					}
				}
			}
			cout << "Turn Order" << endl;
			for (int i = 0; i < n; i++) {
				cout << player[i].getName() << endl;
			}
		}
		
	

}



