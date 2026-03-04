#include <iostream>
using namespace std;

class Target {
	// This is what the Client want/expect to be able to use
	int volt = 220;
public:
	virtual ~Target() {};
	virtual void chargePhone() = 0; // Client just wants to call this
};

class Service {
	// This is an incompatible interface (3rd party, legacy code, etc...) to the Target the CLIENT want
public:
	int myElec() {
		return 440;
	}
};

class Adapter : public Target {
	// The middle man that solve the problem of both side
	// Follows Structural Object Composition - contain the adaptee aka Service class's ptr
private:
	Service* adaptee;
public:
	Adapter(Service* aService) : adaptee(aService) {};
	void chargePhone() override {
		int service_elec = adaptee->myElec();
		int appropriate_elec = service_elec / 2;
		
		if (appropriate_elec <= 220) {
			cout << "I can be charged now:)" << endl;
		}
	}
};