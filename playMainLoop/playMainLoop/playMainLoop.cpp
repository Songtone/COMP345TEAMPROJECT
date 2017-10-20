// playMainLoop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void mainPlayerLoop();

int main() {


	system("pause");
	return 0;
}

void mainPlayerLoop() {
	bool phases = true;
	bool rF = true;
	int x;

	while (phases) {
		cout << "Choose an option" << endl;
		cout << "1. Reinforce" << endl;
		cout << "2. Attack" << endl;
		cout << "3. Fortify" << endl;
		cin >> x;
		switch (x) {
		case '1': if (rF == true) {
			cout << "Reinforcement Initiated!" << endl;
			cout << "Reinforce function should be here" << endl; // reinforcement() function here
			rF = false;
		}
				  else if (rF == false) {
					  cout << "Reinforcement can only be used once." << endl;
						  cout << "Choose a valide option" << endl;
		}
				  break;
		case '2': cout << "Attack Initiated!" << endl;
			cout << "Attack function should be here." << endl; //attack() function should be here
			break;
		
		case '3': cout << "Fortification Initiated!" << endl;
			phases = false;
			break;
		}

	}
}



