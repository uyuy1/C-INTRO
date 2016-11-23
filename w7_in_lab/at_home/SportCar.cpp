#include "SportCar.h"
#include <iostream>
#include "Car.h"

namespace sict{

	SportCar::SportCar() : Car(0) {

		noOfPassengers_ = 1;

	}
	SportCar::SportCar(int iMaxSpeed, int iPassenger) : Car(iMaxSpeed) {

		noOfPassengers_ = iPassenger;
	}

	 void SportCar::accelerate()  {

		 speed(speed() + 40);


		

	}
	void SportCar::brake() {

		speed(speed() - 10);

	}

	std::ostream& SportCar::display(std::ostream& ostr) const {

		if (speed() > 0) {
			ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is traveling at a speed of " << speed() << " km/h." ;
		}
		if (speed() == 0) {
			ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is parked.";
		}
		return ostr;

	}



}