#include "stdafx.h"
#include "Phases.h"
#include "Players.h"
#include <iostream>
using namespace std;

int main(void) {
	//create Phases to be observeds
	Players *players1 = new Players;
	Players *players2 = new Players;

	//create a digital clock that is connected to the Phases
	Phases *phases1 = new Phases(players1);
	Phases *phases2 = new Phases(players2);
	

	//Advancing the Phases updates the digital clock
	//as tick() calls Update() after it changed its state

	
	players1->startPlayers(1);
	cout << "NEXT PLAYER \n" << endl;
	players2->startPlayers(2);



	system("pause");
	return 0;
}