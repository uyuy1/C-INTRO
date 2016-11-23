#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include "Product.h"
#include <cstring>
#include "Streamable.h"
#include "general.h"
using namespace std;
namespace sict{

	Product::Product(){
		sku_[0] = 0;
		name_ = nullptr;
		price_ = 0;
		taxed_ = false;
		quantity_ = 0;
		qtyNeeded_ = 0;

	}

	Product::Product(const char* skuu, const char* name, double price, int needed, bool tax){
		strncpy(sku_, skuu, MAX_SKU_LEN);
		sku_[MAX_SKU_LEN + 1] = '\0';
		name_ = new char[strlen(name) + 1];
		strcpy(name_, name);
		quantity_ = 0;
		price_ = price;
		qtyNeeded_ = needed;
		taxed_ = tax;
	}

	Product::Product(const Product& original){
		strcpy(sku_, original.sku_);
		name_ = new char[strlen(original.name_) + 1];
		strcpy(name_, original.name_);
		price_ = original.price_;
		taxed_ = original.taxed_;
		quantity_ = original.quantity_;
		qtyNeeded_ = original.qtyNeeded_;
	}

	Product& Product::operator=(const Product& rightSide){
		if (this != &rightSide)
		{
			strcpy(sku_, rightSide.sku_);
			if (name_ != nullptr)
			{
				delete[] name_;
			}
			name_ = new char[strlen(rightSide.name_) + 1];
			strcpy(name_, rightSide.name_);
			price_ = rightSide.price_;
			taxed_ = rightSide.taxed_;
			quantity_ = rightSide.quantity_;
			qtyNeeded_ = rightSide.qtyNeeded_;
			
		}
		return *this;
	}

	Product::~Product(){
		delete[] name_;
	}

	bool Product::isEmpty()const{
		if (sku_[0] == 0 && name_ == nullptr && price_ == 0 && taxed_ == false 
			&& quantity_ == 0 && qtyNeeded_ == 0)
		{
			return true;
		}
		else {
			return false;
		}
	}

	void Product::sku(char* const skuu){
		strncpy(sku_, skuu, MAX_SKU_LEN);
		sku_[MAX_SKU_LEN + 1] = '\0';
	}

	void Product::price(double priceu){
		price_ = priceu;
	}

	void Product::name(char* const nameu){
		name_ = new char[strlen(nameu) + 1];
		strcpy(name_, nameu);
	}

	void Product::taxed(bool taxu){
		taxed_ = taxu;
	}

	void Product::quantity(int quantityu){
		quantity_ = quantityu;
	}

	void Product::qtyNeeded(int neededu){
		qtyNeeded_ = neededu;
	}

	const char* Product::sku()const{
		return sku_;
	}

	double Product::price()const{
		return price_;
	}

	const char* Product::name()const{
		return name_;
	}

	bool Product::taxed()const{
		return taxed_;
	}

	int Product::quantity()const{
		return quantity_;
	}

	int Product::qtyNeeded()const{
		return qtyNeeded_;
	}

	double Product::cost()const{
		if (taxed())
		{
			double myPrice = price()*0.13;
			double total = price() + myPrice;
			return total;
		}
		else
		{
			return price_;
		}
	}

	bool Product::operator==(const char* string){
		if (strcmp(string, sku_) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Product::operator+=(int num) {	
		quantity_ = quantity_ + num;
		return quantity_;
	}

	int Product::operator-=(int num) {
		quantity_ = quantity_ - num;
		return quantity_;
	}

	double operator+=(double& leftt, const Product& rightt) {
		leftt = leftt + (rightt.cost() * rightt.quantity());
		return leftt;
	}
	std::istream& operator>>(std::istream& is, Product& D) {
		return D.read(is);
	}

	std::ostream& operator<<(std::ostream& os, Product& D) {
		return D.write(os,true);
	}
}