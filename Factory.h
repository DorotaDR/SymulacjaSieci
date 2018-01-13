#ifndef FACTORY_H_
#define FACTORY_H_


// #include "Others.h"  <- biblioteki z klasami: Worker, Ramp, StoreHouse
#include <list>
#include <vector>


// ------ FACTORY


class Factory {

private:
	std::list<Ramp*> ramps;
	std::list<Worker*> workers;
	std::list<Storehouse*> storehouses;

public:
// ------ ADD FUNCTIONS
	Ramp* addRamp();
	Worker* addWorker();
	Storehouse* addStorehouse();

// ------ GET FUNCTIONS
	std::vector<Ramp> getRamps();
	std::vector<Worker> getWorkers();
	std::vector<Storehouse> getStorehouses();

// ------ DELETE FUNCTIONS
	void deleteRamps(std::vector<Ramp> rampsToDelete);
	void deleteWorkers(std::vector<Worker> workersToDelete);
	void deleteStorehouses(std::vector<Storehouse> storehousesToDelete);

// ------ FRIEND FUNCTIONS:
	friend class RaportOfNet;
};




#endif /* FACTORY_H_ */
