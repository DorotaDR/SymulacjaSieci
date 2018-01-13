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
	virtual void create() = 0;			//tworzy i wyświetla raport
	virtual bool isItTime(int RundNum) = 0; 	//sprawdza czy w tej turze utworzyć raport
}
// ------ EVERYXROUNDS
class EveryXRounds: public RaportOfNet{
private:
	int interval;
	
public:
	void create();				//tworzy i wyświetla raport
	bool isItTime(int RundNum); 		//sprawdza czy w tej turze utworzyć raport
}
// ------ GIVENROUNDS
class GivenRounds: public RaportOfNet{
private:
	int givenRounds;
public:
	void create();				//tworzy i wyświetla raport
	bool isItTime(int RundNum); 		//sprawdza czy w tej turze utworzyć raport
}
