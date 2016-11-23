// compilation safegaurds

#ifndef SICT_WEATHER_H_
#define SICT_WEATHER_H_

/*Weather.h*/

 // sict namespace
namespace sict{


	class Weather{
		// member variables
	public:

		char  calDate[8];
		double highTemp;
		double lowTemp;

	public:
		// member function
		void set(const char* , double , double );
		void display() const;

	};

}

#endif
