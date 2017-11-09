#include "stdafx.h"
#include "Phases.h"
#include "Players.h"
#include <iostream>

//CONCRETE OBSERVER
using namespace std;

Phases::Phases() {

};
Phases::Phases(Players* s) {
	//Upon instantiation, attaches itself to a Phases
	_subject = s;
	_subject->Attach(this);
};
Phases::~Phases() {
	//Upon destruction, detachess itself from a clock timer
	_subject->Detach(this);
};
void Phases::Update(int n) {
	//called by notify() when state subeject changes
	display(n);
};
void Phases::display(int n) {
	if (n == 1) {
		if (_subject->getPhase() == 0) {
			cout << "Player " << n << endl;
			cout << "This is the reinforce phase" << endl;
			cout << "You have 20 armies to place" << endl;
			cout << endl;
		}
		else if (_subject->getPhase() == 1) {
			cout << "Player " << n << endl;
			cout << "This is the attack phase" << endl;
			cout << endl;
		}
		else if (_subject->getPhase() == 2) {
			cout << "Player " << n << endl;
			cout << "This is the fortification phase" << endl;
			cout << endl;
		}
	}
	else if (n == 2) {
		if (_subject->getPhase() == 0) {
			cout << "Player " << n << endl;
			cout << "This is the reinforce phase" << endl;
			cout << "You have 40 armies to place" << endl;
			cout << endl;
		}
		else if (_subject->getPhase() == 1) {
			cout << "Player " << n << endl;
			cout << "This is the attack phase" << endl;
			cout << endl;
		}
		else if (_subject->getPhase() == 2) {
			cout << "Player " << n << endl;
			cout << "This is the fortification phase" << endl;
			cout << endl;
		}
	}
};