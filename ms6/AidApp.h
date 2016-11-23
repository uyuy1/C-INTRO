#ifndef _SICT_AIDAPP_H
#define _SICT_AIDAPP_H
#include "Product.h"
#include <iostream>
#include <fstream>
using namespace std;
namespace sict {
	class AidApp {
	private:
		char filename_[256];
		Product* product_[MAX_NO_RECS];
		fstream datafile_;
		int noOfProducts_;
		AidApp(const AidApp& a) = delete;
		AidApp& operator=(const AidApp& a) = delete;
		void pause()const;
		int menu();
		void loadRecs();
		void saveRecs();
		void listProducts()const;
		int SearchProducts(const char* sku)const;
		void addQty(const char* sku);
		void addProduct(bool isPerishable);


	public:
		AidApp(const char* filename);
		int run();
	};

}


#endif