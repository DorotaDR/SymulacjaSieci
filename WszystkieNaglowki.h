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
	int counter;
public:
	MathPreferences();
	MathPreferences(Receiver*);
	void addPref(Receiver* idReceiver);
	void addPref(Receiver* idReceiver, int prob);
	void deletePref(Receiver* idToDelete);
};


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
	virtual void create() = 0;		//tworzy i wyświetla raport
}
// ------ RAPORTOFNET
class RaportOfNet: public Raport{
private:
	int numberOfRamps;		
	int numberOfWorkers;
	int numberOfStorehauses;
public:
	void create();				//tworzy i wyświetla raport
	getNumberOfRamps(Factory &f);		//sprawdza ilość ramp
	getNumberOfWorkers(Factory &f);		//sprawdza ilość robotników
	getNumberOfStorehauses(Factory &f);	//sprawdza ilość magazynów
}
// ------ RAPORTOFSYMULATION
class RaportOfNet: public Raport{
public:
	virtual void create() = 0;		//tworzy i wyświetla raport
	virtual bool isItTime(RundNum) = 0; 	//sprawdza czy w tej turze utworzyć raport
}
// ------ EVERYXROUNDS
class EveryXRounds: public RaportOfNet{
private:
	int interval;
	
public:
	void create();				//tworzy i wyświetla raport
	bool isItTime(RundNum); 		//sprawdza czy w tej turze utworzyć raport
}
// ------ GIVENROUNDS
class GivenRounds: public RaportOfNet{
public:
	void create();				//tworzy i wyświetla raport
	vbool isItTime(RundNum); 		//sprawdza czy w tej turze utworzyć raport
}
