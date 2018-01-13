#include "MathPreferencies.h"
#include "Receiver.h"  /////////// !!!!!!!!!!!!!!!!!!!
#include <iostream>
#include <string>

// ------ MATHPREFERENCES
class MathPreferences {

private:
	std::map<Receiver*, int> preferences;
	int counter;

public:
	MathPreferences(){
		preferences[NULL]=0;
		counter = 0;
	}
	MathPreferences(Receiver* idReceiver) {
		preferences[idReceiver]=1;
		counter = 1;
	}
	void addPref(Receiver* idReceiver) {
		auto defaultProb = 1/(counter+1);
		addPref(idReceiver, defaultProb);
	}
	void addPref(Receiver* idReceiver, int prob) {
		counter++;
		preferences[idReceiver] = prob;

		Receiver* highest = preferences.rbegin()->first; // key value of last element

		std::map<Receiver*, float>::iterator it = preferences.begin();
		do {
			if (it->first != idReceiver) {
				it->second = (it->second) * (1 - prob);
			}
		} while (preferences((*it++).first, highest));

	}
	void deletePref(Receiver* idToDelete) {

		float probToDelete = preferences[idToDelete];
		preferences.erase(idToDelete);
		counter --;
		Receiver* highest = preferences.rbegin()->first; // key value of last element

		std::map<Receiver*, float>::iterator it = preferences.begin();
		do {
				it->second = (it->second) / (1 - probToDelete);
		} while (preferences((*it++).first, highest));
	}
};
