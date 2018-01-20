// #include "Others.h"  <- biblioteki z klasami: Worker, Ramp, StoreHouse
#include <list>
#include "raport.h"

class Raport{
public:
	virtual void create() = 0;		//tworzy i wyœwietla raport
}
// ------ RAPORTOFNET
class RaportOfNet: public Raport{
public:
	void create(){                  //tworzy i wyœwietla raport
	cout<<" == LOADING RAMPS == "<<endl;
	list<Ramp*>::iterator it;
    for( it=ramps.begin(); it!=ramps.end(); ++it )   //number of ramps
        {
        cout<<"LOADING RAMP #"<<it.getID<<endl;
        cout<<"Delivery interval: "<<it.getFrequency<<endl;
        cout<<"Receivers:"<<endl;
        for(auto &x : it.MathPreferences)
            {
            cout<<"worker #"<<x.idReceiver<<" (p = "<<x.prob<< ")"<< endl;
            }
        }
    cout<<" == WORKERS == "<<endl;
	list<Worker*>::iterator it;
    for( it=workers.begin(); it!=workers.end(); ++it )    //number of ramps
        {
        cout<<"WORKER #"<<it.getID<<endl;
        cout<<"Processing time: "<<it.getTime<<endl;
        cout<<"Queue type: "<<it.getType<<endl;
        cout<<"Receivers:"<<endl;
        for(auto &x : it.MathPreferences)
            {
            if(typeid(x) == typeid(Worker)){
                cout<<"worker #"<<x.workerID<<" (p = "<<x.prob<< ")"<< endl;
            }
            }
        for(auto &x : it.MathPreferences)
            {
            if(typeid(x) == typeid(Storehouse)){
                cout<<"storehouse #"<<storehouseID<<" (p = "<<x.prob<< ")"<< endl;
            }
            }
        }
    cout<<" == STOREHOUSES == "<<endl;
	list<Storehouse*>::iterator it;
    for( it=storehouses.begin(); it!=storehouses.end(); ++it )    //number of ramps
        {
        cout<<"STOREHOUSE#"<<it.getID<<endl;
        }
    }
}
// ------ RAPORTOFSYMULATION
class RaportOfSymulation: public Raport{
public:
	virtual void create() = 0;			//tworzy i wyœwietla raport
	virtual bool isItTime(int RundNum) = 0; 	//sprawdza czy w tej turze utworzyæ raport
}
// ------ EVERYXROUNDS
class EveryXRounds: public RaportOfSymulation{
private:
	int interval;

public:
	void create();				//tworzy i wyœwietla raport
	bool isItTime(int RundNum); 		//sprawdza czy w tej turze utworzyæ raport
}
// ------ GIVENROUNDS
class GivenRounds: public RaportOfSymulation{
private:
	int givenRounds;

public:
	void create();				//tworzy i wyswietla raport
	bool isItTime(int RundNum); 		//sprawdza czy w tej turze utworzyc raport
}
