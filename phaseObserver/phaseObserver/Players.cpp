#include "stdafx.h"
#include "Players.h"

//CONCRETE SUBJECT
Players::Players() {

};
Players::~Players() {

};
void Players::startPlayers(int n) {

	reinforce(n);
	system("pause");
	attack(n);
	system("pause");
	fortification(n);

};
void Players::reinforce(int n) {
	phase = 0;
	Notify(n);
};
void Players::attack(int n) {
	phase = 1;
	Notify(n);
};
void Players::fortification(int n) {
	phase = 2;
	Notify(n);
}
