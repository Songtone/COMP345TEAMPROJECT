#include "stdafx.h"
#include "Phases.h"
#include "Players.h"
#include <iostream>
#include <string>

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
	attack = true;
	if (n == 1) {
		if (_subject->getPhase() == 0) {
			cout << "Player " << n << endl;
			cout << "This is the reinforce phase" << endl;
			cout << "You have 10 armies to place" << endl;
			cout << "Please choose a country to reinforce!" << endl;
			cin >> countryToReinforce;
			cout << countryToReinforce << " will receive 10 armies as reinforcement!" << endl;
			cout << endl;
		}
		else if (_subject->getPhase() == 1) {
			while (attack) {
				cout << "Player " << n << endl;
				cout << "Do you want to Attack? Y/N" << endl;
				cin >> confirm;
				if (confirm == "Y" || confirm == "y") {
					cout << "Player " << n << endl;
					cout << "This is the attack phase" << endl;
					cout << "Please select a country to attack from!" << endl;
					cin >> countryAttack;
					cout << "You are Attacking from " << countryAttack << endl;
					cout << "Please select a country to attack!" << endl;
					cin >> countryDefense;
					cout << "You are Attacking " << countryDefense << endl;
					cout << "How many attackers are you attacking with?" << endl;
					cin >> numberOfAttackers;
					if (numberOfAttackers == 1) {
						cout << "You are rolling 1 dice." << endl;
					}
					else if (numberOfAttackers == 2) {
						cout << "You are rolling 2 dice." << endl;
					}
					else if (numberOfAttackers == 3) {
						cout << "You are rolling 3 dice." << endl;
					}
					cout << endl;
				}
				else if (confirm == "N" || confirm == "n") {
					cout << "Player " << n << endl;
					cout << "End of Attack Phase" << endl;
					cout << endl;
					attack = false;

				}
			}
		}
		else if (_subject->getPhase() == 2) {
			cout << "Player " << n << endl;
			cout << "This is the fortification phase" << endl;
			cout << "Select a country to fortify" << endl;
			cin >> countryToReceiveFortify;
			cout << "Please select a country to fortify from!" << endl;
			cin >> countryToGiveFortify;
			cout << "Please choose how many armies to fortify with!" << endl;
			cin >> numberOfArmiesToFortify;
			cout << countryToReceiveFortify << " will receive " << numberOfArmiesToFortify << " armies from " << countryToGiveFortify << endl;
			cout << endl;
		}
	}
	else if (n == 2) {
		if (_subject->getPhase() == 0) {
			cout << "Player " << n << endl;
			cout << "This is the reinforce phase" << endl;
			cout << "You have 20 armies to place" << endl;
			cout << "Please choose a country to reinforce!" << endl;
			cin >> countryToReinforce;
			cout << countryToReinforce << " will receive 20 armies as reinforcement!" << endl;
			cout << endl;
		}
		else if (_subject->getPhase() == 1) {
			while (attack) {
				cout << "Player " << n << endl;
				cout << "Do you want to Attack? Y/N" << endl;
				cin >> confirm;
				if (confirm == "Y" || confirm == "y") {
					cout << "Player " << n << endl;
					cout << "This is the attack phase" << endl;
					cout << "Please select a country to attack from!" << endl;
					cin >> countryAttack;
					cout << "You are Attacking from " << countryAttack << endl;
					cout << "Please select a country to attack!" << endl;
					cin >> countryDefense;
					cout << "You are Attacking " << countryDefense << endl;
					cout << "How many attackers are you attacking with?" << endl;
					cin >> numberOfAttackers;
					if (numberOfAttackers == 1) {
						cout << "You are rolling 1 dice." << endl;
					}
					else if (numberOfAttackers == 2) {
						cout << "You are rolling 2 dice." << endl;
					}
					else if (numberOfAttackers == 3) {
						cout << "You are rolling 3 dice." << endl;
					}
					cout << endl;
				}
				else if (confirm == "N" || confirm == "n") {
					cout << "Player " << n << endl;
					cout << "End of Attack Phase" << endl;
					cout << endl;
					attack = false;

				}
			}
		}
		else if (_subject->getPhase() == 2) {
			cout << "Player " << n << endl;
			cout << "This is the fortification phase" << endl;
			cout << "Select a country to fortify" << endl;
			cin >> countryToReceiveFortify;
			cout << "Please select a country to fortify from!" << endl;
			cin >> countryToGiveFortify;
			cout << "Please choose how many armies to fortify with!" << endl;
			cin >> numberOfArmiesToFortify;
			cout << countryToReceiveFortify << " will receive " << numberOfArmiesToFortify << " armies from " << countryToGiveFortify << endl;
			cout << endl;
		}
	}
	else if (n == 3) {
		if (_subject->getPhase() == 0) {
			cout << "Player " << n << endl;
			cout << "This is the reinforce phase" << endl;
			cout << "You have 30 armies to place" << endl;
			cout << "Please choose a country to reinforce!" << endl;
			cin >> countryToReinforce;
			cout << countryToReinforce << " will receive 30 armies as reinforcement!" << endl;
			cout << endl;
		}
		else if (_subject->getPhase() == 1) {
			while (attack) {
				cout << "Player " << n << endl;
				cout << "Do you want to Attack? Y/N" << endl;
				cin >> confirm;
				if (confirm == "Y" || confirm == "y") {
					cout << "Player " << n << endl;
					cout << "This is the attack phase" << endl;
					cout << "Please select a country to attack from!" << endl;
					cin >> countryAttack;
					cout << "You are Attacking from " << countryAttack << endl;
					cout << "Please select a country to attack!" << endl;
					cin >> countryDefense;
					cout << "You are Attacking " << countryDefense << endl;
					cout << "How many attackers are you attacking with?" << endl;
					cin >> numberOfAttackers;
					if (numberOfAttackers == 1) {
						cout << "You are rolling 1 dice." << endl;
					}
					else if (numberOfAttackers == 2) {
						cout << "You are rolling 2 dice." << endl;
					}
					else if (numberOfAttackers == 3) {
						cout << "You are rolling 3 dice." << endl;
					}
					cout << endl;
				}
				else if (confirm == "N" || confirm == "n") {
					cout << "Player " << n << endl;
					cout << "End of Attack Phase" << endl;
					cout << endl;
					attack = false;

				}
			}
		}
		else if (_subject->getPhase() == 2) {
			cout << "Player " << n << endl;
			cout << "This is the fortification phase" << endl;
			cout << "Select a country to fortify" << endl;
			cin >> countryToReceiveFortify;
			cout << "Please select a country to fortify from!" << endl;
			cin >> countryToGiveFortify;
			cout << "Please choose how many armies to fortify with!" << endl;
			cin >> numberOfArmiesToFortify;
			cout << countryToReceiveFortify << " will receive " << numberOfArmiesToFortify << " armies from " << countryToGiveFortify << endl;
			cout << endl;
		}
	}
	else if (n == 4 ) {
		if (_subject->getPhase() == 0) {
			cout << "Player " << n << endl;
			cout << "This is the reinforce phase" << endl;
			cout << "You have 40 armies to place" << endl;
			cout << "Please choose a country to reinforce!" << endl;
			cin >> countryToReinforce;
			cout << countryToReinforce << " will receive 40 armies as reinforcement!" << endl;
			cout << endl;
		}
		else if (_subject->getPhase() == 1) {
			while (attack) {
				cout << "Player " << n << endl;
				cout << "Do you want to Attack? Y/N" << endl;
				cin >> confirm;
				if (confirm == "Y" || confirm == "y") {
					cout << "Player " << n << endl;
					cout << "This is the attack phase" << endl;
					cout << "Please select a country to attack from!" << endl;
					cin >> countryAttack;
					cout << "You are Attacking from " << countryAttack << endl;
					cout << "Please select a country to attack!" << endl;
					cin >> countryDefense;
					cout << "You are Attacking " << countryDefense << endl;
					cout << "How many attackers are you attacking with?" << endl;
					cin >> numberOfAttackers;
					if (numberOfAttackers == 1) {
						cout << "You are rolling 1 dice." << endl;
					}
					else if (numberOfAttackers == 2) {
						cout << "You are rolling 2 dice." << endl;
					}
					else if (numberOfAttackers == 3) {
						cout << "You are rolling 3 dice." << endl;
					}
					cout << endl;
				}
				else if (confirm == "N" || confirm == "n") {
					cout << "Player " << n << endl;
					cout << "End of Attack Phase" << endl;
					cout << endl;
					attack = false;

				}
			}
		}
		else if (_subject->getPhase() == 2) {
			cout << "Player " << n << endl;
			cout << "This is the fortification phase" << endl;
			cout << "Select a country to fortify" << endl;
			cin >> countryToReceiveFortify;
			cout << "Please select a country to fortify from!" << endl;
			cin >> countryToGiveFortify;
			cout << "Please choose how many armies to fortify with!" << endl;
			cin >> numberOfArmiesToFortify;
			cout << countryToReceiveFortify << " will receive " << numberOfArmiesToFortify << " armies from " << countryToGiveFortify << endl;
			cout << endl;
		}
	}
	else if (n == 5) {
		if (_subject->getPhase() == 0) {
			cout << "Player " << n << endl;
			cout << "This is the reinforce phase" << endl;
			cout << "You have 50 armies to place" << endl;
			cout << "Please choose a country to reinforce!" << endl;
			cin >> countryToReinforce;
			cout << countryToReinforce << " will receive 50 armies as reinforcement!" << endl;
			cout << endl;
		}
		else if (_subject->getPhase() == 1) {
			while (attack) {
				cout << "Player " << n << endl;
				cout << "Do you want to Attack? Y/N" << endl;
				cin >> confirm;
				if (confirm == "Y" || confirm == "y") {
					cout << "Player " << n << endl;
					cout << "This is the attack phase" << endl;
					cout << "Please select a country to attack from!" << endl;
					cin >> countryAttack;
					cout << "You are Attacking from " << countryAttack << endl;
					cout << "Please select a country to attack!" << endl;
					cin >> countryDefense;
					cout << "You are Attacking " << countryDefense << endl;
					cout << "How many attackers are you attacking with?" << endl;
					cin >> numberOfAttackers;
					if (numberOfAttackers == 1) {
						cout << "You are rolling 1 dice." << endl;
					}
					else if (numberOfAttackers == 2) {
						cout << "You are rolling 2 dice." << endl;
					}
					else if (numberOfAttackers == 3) {
						cout << "You are rolling 3 dice." << endl;
					}
					cout << endl;
				}
				else if (confirm == "N" || confirm == "n") {
					cout << "Player " << n << endl;
					cout << "End of Attack Phase" << endl;
					cout << endl;
					attack = false;

				}
			}
		}
		else if (_subject->getPhase() == 2) {
			cout << "Player " << n << endl;
			cout << "This is the fortification phase" << endl;
			cout << "Select a country to fortify" << endl;
			cin >> countryToReceiveFortify;
			cout << "Please select a country to fortify from!" << endl;
			cin >> countryToGiveFortify;
			cout << "Please choose how many armies to fortify with!" << endl;
			cin >> numberOfArmiesToFortify;
			cout << countryToReceiveFortify << " will receive " << numberOfArmiesToFortify << " armies from " << countryToGiveFortify << endl;
			cout << endl;
		}
	}
	else if (n == 6) {
		if (_subject->getPhase() == 0) {
			cout << "Player " << n << endl;
			cout << "This is the reinforce phase" << endl;
			cout << "You have 60 armies to place" << endl;
			cout << "Please choose a country to reinforce!" << endl;
			cin >> countryToReinforce;
			cout << countryToReinforce << " will receive 60 armies as reinforcement!" << endl;
			cout << endl;
		}
		else if (_subject->getPhase() == 1) {
			while (attack) {
				cout << "Player " << n << endl;
				cout << "Do you want to Attack? Y/N" << endl;
				cin >> confirm;
				if (confirm == "Y" || confirm == "y") {
					cout << "Player " << n << endl;
					cout << "This is the attack phase" << endl;
					cout << "Please select a country to attack from!" << endl;
					cin >> countryAttack;
					cout << "You are Attacking from " << countryAttack << endl;
					cout << "Please select a country to attack!" << endl;
					cin >> countryDefense;
					cout << "You are Attacking " << countryDefense << endl;
					cout << "How many attackers are you attacking with?" << endl;
					cin >> numberOfAttackers;
					if (numberOfAttackers == 1) {
						cout << "You are rolling 1 dice." << endl;
					}
					else if (numberOfAttackers == 2) {
						cout << "You are rolling 2 dice." << endl;
					}
					else if (numberOfAttackers == 3) {
						cout << "You are rolling 3 dice." << endl;
					}
					cout << endl;
				}
				else if (confirm == "N" || confirm == "n") {
					cout << "Player " << n << endl;
					cout << "End of Attack Phase" << endl;
					cout << endl;
					attack = false;

				}
			}
		}
		else if (_subject->getPhase() == 2) {
			cout << "Player " << n << endl;
			cout << "This is the fortification phase" << endl;
			cout << "Select a country to fortify" << endl;
			cin >> countryToReceiveFortify;
			cout << "Please select a country to fortify from!" << endl;
			cin >> countryToGiveFortify;
			cout << "Please choose how many armies to fortify with!" << endl;
			cin >> numberOfArmiesToFortify;
			cout << countryToReceiveFortify << " will receive " << numberOfArmiesToFortify << " armies from " << countryToGiveFortify << endl;
			cout << endl;
		}
	}
};