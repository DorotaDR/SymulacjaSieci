#ifndef MATHPREFERENCIES_H_
#define MATHPREFERENCIES_H_

#include <map>

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


#endif /* MATHPREFERENCIES_H_ */
