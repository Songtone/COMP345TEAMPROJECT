#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H

#include "stdafx.h"
#include "Observer.h"
#include <list>

using namespace std;

class Subject {
public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify(int n,int p);
	Subject();
	~Subject();
private:
	list<Observer*> *_observers;
};

#endif // !SUBJECT_H
