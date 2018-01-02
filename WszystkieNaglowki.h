

// ------ FACTORY

class Factory{

private:
	std::vector<Ramp> ramps;
	std::vector<Worker> workers;
	std::vector<Storehause> storehauses;

public:
	void addRamp()
	void addWorker()
	void addStorehouse()

	std::vector<Ramp> getRamps();
	std::vector<Worker> getWorkers();
	std::vector<Storehause> getStorehouses();

	void deleteRamps();
	void deleteWorkers();
	void deleteStorehouses();
}

// ------ PRODUCT

// ------ RAMP
class Ramp{
private: 
	MathPreferences preferences;
	double frequency;
public: 
	friend void SendTo();
}

// ------ WORKER

// ------ STOREHAUSE

// ------ RECEIVER



// ------ MATHPREFERENCES

// ------ PRIORITY

// ------ LIFO

// ------ FIFO



// ------ RAPORT

// ------ RAPORTOFNET

// ------ RAPORTOFSYMULATION

// ------ EVERYXROUNDS

// ------ GIVENROUNDS
