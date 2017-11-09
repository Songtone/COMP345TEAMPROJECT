#pragma once
#include "stdafx.h"
#include "Observer.h"
#include "Players.h"

class Phases : public Observer {
public:
	Phases();
	Phases(Players* s);
	~Phases();
	void Update(int n);
	void display(int n);
	bool attack = true;
	string confirm;
private:
	Players* _subject;
};