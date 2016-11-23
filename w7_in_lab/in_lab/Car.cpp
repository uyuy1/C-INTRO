#include "Car.h"
using namespace std;
namespace sict{
	
	Car::Car(int num) {

		speed_ = 0;

		if (num == 0) {

			maxSpeed_ = 100;

		}

	}

	int Car::speed() const{
		return speed_;
	}

	void Car::speed(int value) {

		speed_ = value;

		if (value > maxSpeed_) {
			maxSpeed_ = value;
			
		}
		if (value < 0) {
			speed_ = 0;
		}

	}
	int Car::maxSpeed() const {

		return maxSpeed_;
	}


}