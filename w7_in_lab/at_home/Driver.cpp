#include <iostream>
#include <cstring>
#include "Driver.h"
#include "Car.h"
using namespace std;
namespace sict {

	Driver::Driver(const char* name, Car& cRef) : car_(cRef){

		strcpy(name_, name);
		


	}
	void Driver::drive() {
		car_.accelerate();
		car_.brake();
		showStatus();
		
	}
	void Driver::stop() {

		while (car_.speed() != 0) {

			car_.brake();
		
		}
		showStatus();
	
		
	}
	void Driver::showStatus() {

		cout << name_ << " is driving this car." << endl;
		car_.display(cout);
		cout << endl;
	}

	std::ostream& operator<<(std::ostream& os, Car& car_) {
		car_.display(cout);
		return os;
	}

}