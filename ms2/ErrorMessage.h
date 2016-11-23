#ifndef SICT_ERRORMESSAGE_H__
#define SICT_ERRORMESSAGE_H__
#include <iostream>
namespace sict{

	class ErrorMessage {
	private:
		char* message_;
	public:

		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const char* errorMessage);
		virtual ~ErrorMessage();
		void clear();
		bool isClear()const;
		void message(const char* value);
		const char* message()const;

		ErrorMessage();
		ErrorMessage(const char* errorMessage);
		ErrorMessage(const ErrorMessage& em) = delete;
	};

	std::ostream& operator<<(std::ostream& os, const ErrorMessage& m);
	
		



}
#endif

