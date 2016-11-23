#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR  3
#define DAY_ERROR  4
#include <iostream>

namespace sict{



	class Date  {

		

	private:
		int value()const;
		void errCode(int errorCode);
		int year_;
		int mon_;
		int day_;
		int readErrorCode_;
	


	public:

		bool operator==(const Date& D)const;
		bool operator!=(const Date& D)const;
		bool operator<(const Date& D)const;
		bool operator>(const Date& D)const;
		bool operator<=(const Date& D)const;
		bool operator>=(const Date& D)const;
		int errCode()const;
		bool bad()const;

		Date();
		Date(int year, int mon, int day);

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;

		int mdays()const;
		void validate();

	};

	std::istream& operator>>(std::istream& is, Date& D);
	std::ostream& operator<<(std::ostream& os, const Date& D);

}
#endif