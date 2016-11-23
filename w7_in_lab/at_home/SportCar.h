#ifndef SICT_SPORTCAR_H_
#define SICT_SPORTCAR_H_
#include "Car.h"
#include <iostream>

namespace sict{
  class SportCar :public Car  {
	  int noOfPassengers_;
  public:

    // implementations of Vehicle's pure virtual methods
	  SportCar();
	  SportCar(int iMaxSpeed, int iPassenger);
	  void accelerate();
	  void brake();
	  std::ostream& display(std::ostream& ostr) const;

  };
}
#endif