#define _CRT_NO_WARNINGS
#include "ErrorMessage.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace sict{

	void ErrorMessage::clear(){

		delete[] message_;
		message_ = nullptr;


	}

	bool ErrorMessage::isClear()const {

		if (message_ == nullptr) {
			return true;
		}
		else {
			return false;
		}

	}

	void ErrorMessage::message(const char* value) {

		delete[] message_;

		message_ = new char[strlen(value) + 1];

		strcpy(message_, value);

	}

	const char* ErrorMessage::message()const {

		return message_;

	}

	ErrorMessage::~ErrorMessage() {

		delete[] message_;

	}

	ErrorMessage& ErrorMessage::operator=(const char* errorMessage) {

		delete[] message_;
		message_ = new char[strlen(errorMessage) + 1];
		strcpy(message_, errorMessage);
		return *this;

	}

	ErrorMessage::ErrorMessage() {
	
		message_ = nullptr;

	}

	ErrorMessage::ErrorMessage(const char* errorMessage) {

		message_ = nullptr;
		message(errorMessage);

	}


	std::ostream& operator<<(std::ostream& os, const ErrorMessage& m) {

		if (!m.isClear()) 
		{
			cout << m.message();

		}
		else {
			
		}
		return os;

	}

}