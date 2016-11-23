// OOP244 Workshop 2: Compound types and privacy
// File	???????
// Version 1.0
// Date	???????????
// Author	?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// 
///////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict{
  // member functions' (methods') definition go here

		void AccountNumber::name(const char name[]) {
			strcpy(_name, name);
		}
		void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber) {


			
			_bankCode = bankCode;
			_branchCode = branchCode;
			_accountNumber = accountNumber;
			if (bankCode >= MIN_BANKCODE&&bankCode <= MAX_BANKCODE&&
			branchCode >= MIN_BRANCHCODE&&branchCode <= MAX_BRANCHCODE&&
			accountNumber >= MIN_ACCNO&&accountNumber <= MAX_ACCNO) {

				_validAccNumber = true;
			}
			else {
				_validAccNumber = false;
			}

		}
		void AccountNumber::display() const {
			if (AccountNumber::isValid()== true) {
				cout << "Name: " << _name << ", Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber << endl;
			}
			else {
				cout << _name << " does not have a valid account number." << endl;
			}

		}
		bool AccountNumber::isValid()const {
			return _validAccNumber;
		}

	};



