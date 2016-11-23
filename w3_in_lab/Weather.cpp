/*Weather.cpp*/
//  includes go here

#include<iostream>
#include <cstring>
using namespace std;
#include "Weather.h"
#include <iomanip>

// sict namespace
  // set
namespace sict{

	// display
	
	void Weather::set(const char* iCal, double iLowtemp, double ihigTemp){

		strcpy(calDate, iCal);
		lowTemp = iLowtemp;
		highTemp = ihigTemp;
	
	}

	void Weather::display() const{

		cout << setw(10) << left << setfill('_') << calDate
			<< setw(6) << right << fixed << setprecision(1) << highTemp
			<< setw(6) << right << fixed << setprecision(1) << lowTemp << endl;

	}

};
