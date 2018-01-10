// ------ FACTORY

class Factory{

private:
	std::vector<Ramp> ramps;
	std::vector<Worker> workers;
	std::vector<Storehause> storehauses;

public:
	void addRamp();
	void addWorker();
	void addStorehouse();

	std::vector<Ramp> getRamps();
	std::vector<Worker> getWorkers();
	std::vector<Storehause> getStorehouses();

	void deleteRamps(std::vector<Ramp> rampsToDelete);
	void deleteWorkers(std::vector<Worker> workersToDelete);
	void deleteStorehouses(std::vector<Storehause> storehausesToDelete);
	
	friend class RaportOfNet;
}

// ------ PRODUCT

// ------ RAMP

// ------ WORKER

// ------ STOREHAUSE

// ------ RECEIVER



// ------ MATHPREFERENCES
class MathPreferences{
private:
	std::map<int, int> preferences;
	
public: 
	MathPreferences();
	void add(int id, int prob);
	void delete(int id);0
}


// ------ PRIORITY
class Priority{\
public:
	virtual void push(int PackageId)=0; 		// umieszczenie nowego elementu na szczycie stosu;
    	virtual void pop() = 0; 			// zdjęcie istniejącego elementu ze szczytu stosu;
    	virtual bool empty() = 0; 			// informacja czy stos jest pusty;
   	virtual int  top() = 0;				// zwraca wartość szczytowego elementu na stosie.
}



// ------ LIFO
class Lifo: public Priority{
private:
	std::stack lifo;
public:
	void push(int PackageId); 	// umieszczenie nowego elementu na szczycie stosu;
    	void pop(); 			// zdjęcie istniejącego elementu ze szczytu stosu;
    	bool empty(); 			// informacja czy stos jest pusty;
   	int  top();			// zwraca wartość szczytowego elementu na stosie.
}


// ------ FIFO
class Fifo: public Priority{
private:
	std::stack fifo;
public:
	void push(int PackageId); 	// umieszczenie nowego elementu na szczycie stosu;
    	void pop(); 			// zdjęcie istniejącego elementu ze szczytu stosu;
    	bool empty(); 			// informacja czy stos jest pusty;
   	int  top();			// zwraca wartość szczytowego elementu na stosie.
}


// ------ RAPORT
class Raport{
public:
	virtual void create() = 0;
}
// ------ RAPORTOFNET
class RaportOfNet: public Raport{
private:
	
public:
	void create();
	NumberOfRamps(Factory &f);
	NumberOfWorkers(Factory &f);
	NumberOfStorehauses(Factory &f);
}
// ------ RAPORTOFSYMULATION
class RaportOfNet: public Raport{
public:
	virtual void create() = 0;
}
// ------ EVERYXROUNDS

// ------ GIVENROUNDS
