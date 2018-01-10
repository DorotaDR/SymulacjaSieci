/*
 * AllPriority.cpp
 *
 *  Created on: 10 sty 2018
 *      Author: dydorozn
 */

// ------ PRIORITY

#include "AllPriority.h"
class Priority {
public:
	virtual auto push(int PackageId)=0; // umieszczenie nowego elementu na szczycie stosu;
	virtual auto pop() = 0; // zdjęcie istniejącego elementu ze szczytu stosu;
	virtual auto empty() = 0; 			// informacja czy stos jest pusty;
	virtual auto take() = 0;			// zwraca wartość szczytowego elementu na stosie.
}

// ------ LIFO
class Lifo: public Priority {
private:
	std::stack<int> lifo;
public:
	auto push(int PackageId){ // umieszczenie nowego elementu na szczycie stosu;
		lifo.push(PackageId);
	}
	auto pop(){ 			// zdjęcie istniejącego elementu ze szczytu stosu;
		return lifo.pop();
	}
	auto empty(){ 			// informacja czy stos jest pusty;
		return lifo.empty();
	}
	auto take(){			// zwraca wartość szczytowego elementu na stosie.
		return lifo.top();
	}
}

// ------ FIFO
class Fifo: public Priority {
private:
	std::queue<int> fifo;
public:
	auto push(int PackageId){ // umieszczenie nowego elementu na szczycie stosu;
			fifo.push(PackageId);
		}
		auto pop(){ 			// zdjęcie istniejącego elementu ze szczytu stosu;
			return fifo.pop();
		}
		auto empty(){ 			// informacja czy stos jest pusty;
			return fifo.empty();
		}
		auto take(){			// zwraca wartość ostatniego elementu na stosie.
			return fifo.back();
		}
}


