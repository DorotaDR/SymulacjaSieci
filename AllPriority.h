/*
 * AllPriority.h
 *
 *  Created on: 10 sty 2018
 *      Author: dydorozn
 */

#ifndef ALLPRIORITY_H_
#define ALLPRIORITY_H_

#include <stack>
#include <queue>

// ------ PRIORITY
class Priority {
public:
	virtual auto push(int PackageId)=0; // umieszczenie nowego elementu na szczycie stosu;
	virtual auto pop() = 0; // zdjęcie istniejącego elementu ze szczytu stosu;
	virtual auto empty() = 0; 			// informacja czy stos jest pusty;
	virtual auto take() = 0;	// zwraca wartość szczytowego elementu na stosie.
}

// ------ LIFO
class Lifo: public Priority {
private:
	std::stack<int> lifo;
public:
	auto push(int PackageId); // umieszczenie nowego elementu na szczycie stosu;
	auto pop(); 			// zdjęcie istniejącego elementu ze szczytu stosu;
	auto empty(); 			// informacja czy stos jest pusty;
	auto take();			// zwraca wartość szczytowego elementu na stosie.
}

// ------ FIFO
class Fifo: public Priority {
private:
	std::queue<int> fifo;
public:
	auto push(int PackageId); // umieszczenie nowego elementu na szczycie stosu;
	auto pop(); 			// zdjęcie istniejącego elementu ze szczytu stosu;
	auto empty(); 			// informacja czy stos jest pusty;
	auto take();			// zwraca wartość szczytowego elementu na stosie.
}


#endif /* ALLPRIORITY_H_ */
