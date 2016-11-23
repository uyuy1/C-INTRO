#include <iomanip>
#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;
namespace sict{
  Account::Account(){
    name_[0] = 0;
    balance_ = 0;
  }
  Account::Account(double balance){
    name_[0] = 0;
    balance_ = balance;
  }
  Account::Account(const char name[], double balance){
    strncpy(name_, name, 40);
    name_[40] = 0;
    balance_ = balance;
  }


  void Account::display(bool gotoNewline)const{
    cout << (name_[0] ? name_: "No Name") << ": $" << setprecision(2) << fixed << balance_;
    if (gotoNewline) cout << endl;
  }

  Account& Account::operator+=(const Account& rightOperand){

	balance_ = balance_ + rightOperand.balance_;
	return *this;

  }

  Account& Account::operator=(const Account& rightSide) {
	  if (this != &rightSide)
	  {
		  strncpy(name_, rightSide.name_, 40);
		  name_[40] = '\0';
		  balance_ = rightSide.balance_;
		  
	  }
	  return *this;
  }

  Account& Account::operator=(const char* name){
	  strncpy(name_, name, 40);
	  name_[40] = '\0';
	  return *this;
  }

  Account operator+(const Account& left, const Account& right){
	  Account b;
	  b.balance_ = left.balance_ + right.balance_;
	  b.name_[0] = '\0';
	  return b;	 
  }
  std::ostream& operator<<(std::ostream& os, const Account& a) {
	  a.display(false);
	  return os;
  }
}