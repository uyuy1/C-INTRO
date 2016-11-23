#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Enrollment.h"
#include <cstring>

namespace sict
{

	bool Enrollment::isValid()const
	{
		return name_[0] && code_[0];
	}

	void Enrollment::setEmpty(){
		name_[0] = '\0';
		code_[0] = '\0';
		year_ = 0;
		semester_ = 0;
		slot_ = 0;
		enrolled_ = false;
	}

	bool Enrollment::isEnrolled() const{
		return enrolled_;
	}


	void Enrollment::display(bool nameOnly)const{
		if (isValid()){
			cout << name_;
			if (!nameOnly){
				cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
				cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
			}
		}
		else{
			cout << "Invalid enrollment!" << endl;
		}
	}

	void Enrollment::set(const char* name, const char* code, int year, int
		semester, int time, bool enrolled){


		if ((name != nullptr) && (code != nullptr) && (year >= 2015) &&
			(time > 0) && (time < 6) &&
			(semester > 0) && (semester < 4)) {

			strcpy(name_, name);
			strcpy(code_, code);
			year_ = year;
			slot_ = time;
			semester_ = semester;
			enrolled_ = enrolled;
		

		}
		else{

			setEmpty();

		}

		
	}
	bool Enrollment::hasConflict(const Enrollment &other) const {



		bool ret = false;

		if (other.year_ == year_ && other.semester_ == semester_
			&& other.slot_ == slot_)
		{
			ret = true;
		}
		if (other.year_ < 2015 || year_ < 2015 || other.semester_ < 0 || other.semester_ > 4 || semester_ < 0 || semester_ > 4 || other.slot_ < 0
			|| other.slot_ > 6 || slot_ <0 || slot_  > 6)
		{
			ret = false;
		}

		return ret;
	}

	
	Enrollment::Enrollment(const char* name , const char* code, int year, int
		semester, int slot, bool enrolled) {



		if ((name != nullptr) &&(code != nullptr)&&(year >= 2015) &&
			(slot > 0) &&(slot < 6)&&
			(semester > 0) &&(semester < 4)) {

			strcpy(name_, name);
			strcpy(code_, code);
			year_ = year;
			slot_ = slot;
			semester_ = semester;
			enrolled_ = enrolled;
		

		}

		else{

			setEmpty();

		}
		
	
	}

	Enrollment::Enrollment() {
		name_[0] = '\0';
		code_[0] = '\0';
		year_ = 0;
		semester_ = 0;
		slot_ = 0;
		enrolled_ = false;

	}

};


