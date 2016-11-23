#ifndef SICT_CAR_H_
#define SICT_CAR_H_
#include "Vehicle.h"


namespace sict{
  class Car : public Vehicle{
	  int speed_; 
	  int maxSpeed_;
   
  protected:
	  void speed(int value);
	  int maxSpeed()const;
  
  public:
	  Car(int set);
	  int speed() const;
   
  };

}

#endif