#ifndef RAPORT_H_
#define RAPORT_H_


// #include "Others.h"  <- biblioteki z klasami: Worker, Ramp, StoreHouse
#include <list>


class Raport{
public:
	virtual void create() = 0;		//tworzy i wyœwietla raport
};
// ------ RAPORTOFNET
class RaportOfNet: public Raport{
public:
	void create();				//tworzy i wyœwietla raport
};
// ------ RAPORTOFSYMULATION
class RaportOfSymulation: public Raport{
public:
	virtual void create() = 0;			//tworzy i wyœwietla raport
	virtual bool isItTime(int RundNum) = 0; 	//sprawdza czy w tej turze utworzyæ raport
};
// ------ EVERYXROUNDS
class EveryXRounds: public RaportOfSymulation{
private:
	int interval;

public:
	void create();				//tworzy i wyœwietla raport
	bool isItTime(int RundNum); 		//sprawdza czy w tej turze utworzyæ raport
};
// ------ GIVENROUNDS
class GivenRounds: public RaportOfSymulation{
private:
	int givenRounds;
public:
	void create();				//tworzy i wyœwietla raport
	bool isItTime(int RundNum); 		//sprawdza czy w tej turze utworzyæ raport
};

#endif
