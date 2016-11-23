#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H
#include <iostream>
#include "Streamable.h"
#include "general.h"
using namespace std;

namespace sict {
	class Product : public Streamable {
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;

	public:
		Product();
		Product(const char* skuu, const char* name, double price = 0.0, int needed = 0, bool tax = true);
		Product(const Product& original);
		virtual ~Product();
		bool isEmpty()const;
		/*Setter Functions*/
		void sku(char* const skuu);
		void price(double priceu);
		void name(char* const nameu);
		void taxed(bool taxu);
		void quantity(int quantityu);
		void qtyNeeded(int neededu);
		/* Getter Functions*/
		const char* sku()const;
		double price()const;
		const char* name()const;
		bool taxed()const;
		int quantity()const;
		int qtyNeeded()const;
		double cost()const;
		/*Operator Overloads*/
		Product& operator=(const Product& rightSide);
		bool operator==(const char* string);
		int operator+=(int num);
		int operator-=(int num);

	};
	double operator+=(double& leftt, const Product& rightt);
	std::istream& operator>>(std::istream& is, Product& D);
	std::ostream& operator<<(std::ostream& os, Product& D);
}




#endif