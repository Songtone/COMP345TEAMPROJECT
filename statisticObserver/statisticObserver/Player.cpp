#include "stdafx.h"
#include "Player.h"

//CONCRETE SUBJECT
Player::Player() {

};
Player::~Player() {

};
void Player::showGameStats(int n,int p) {

	showStats(n, p);

};
void Player::showStats(int n, int p) {

	Notify(n, p);
};
