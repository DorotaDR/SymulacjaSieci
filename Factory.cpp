// ------ FACTORY

#include "Factory.h"

class Factory {

private:
	std::list<Ramp*> ramps;
	std::list<Worker*> workers;
	std::list<Storehouse*> storehouses;

public:
// ------ ADD FUNCTIONS

	Ramp* addRamp() {
		Ramp newRamp;
		ramps.push_back(&newRamp);
		return &newRamp;
	}
	Worker* addWorker() {
		Worker newWorker;
		workers.push_back(&newWorker);
		return &newWorker;
	}
	Storehouse* addStorehouse() {
		Storehouse newStorehouse;
		storehouses.push_back(&newStorehouse);
		return &newStorehouse;
	}


// ------ GET FUNCTIONS

	std::vector<Ramp> getRamps() {
		std::vector<Ramp> RampVec;
		for (Ramp* numRamp : ramps) {
			RampVec.push_back(*numRamp);
		}
		return RampVec;
	}
	std::vector<Worker> getWorkers() {
		std::vector<Worker> WorkerVec;
		for (Worker* numWorker : workers) {
			WorkerVec.push_back(*numWorker);
		}
		return WorkerVec;
	}
	std::vector<Storehouse> getStorehouses() {
		std::vector<Storehouse> StorehouseVec;
		for (Storehouse* numStorehouse : storehouses) {
			StorehouseVec.push_back(*numStorehouse);
		}
		return StorehouseVec;
	}

// ------ DELETE FUNCTIONS

	void deleteRamps(std::vector<Ramp> rampsToDelete) {
		for (Ramp numRamps : rampsToDelete) {
			ramps.remove(&numRamps);
		}
	}
	void deleteWorkers(std::vector<Worker> workersToDelete) {
		for (Worker numWorkers : workersToDelete) {
			workers.remove(&numWorkers);
		}
	}
	void deleteStorehouses(std::vector<Storehouse> storehousesToDelete) {
		for (Storehouse numStorehouses : storehousesToDelete) {
			storehouses.remove(&numStorehouses);
		}
	}

// ------ FRIEND FUNCTIONS:

	friend class RaportOfNet;
};

