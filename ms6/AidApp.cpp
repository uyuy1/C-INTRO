#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "AidApp.h"
#include "AmaPerishable.h"
#include "Product.h"
using namespace std;
namespace sict {
	AidApp::AidApp(const char* filename){
		strncpy(filename_, filename, 255);
		filename_[256] = '\0';
		for (int i = 0; i < MAX_NO_RECS; i++)
		{
			product_[i] = nullptr;
		}
		noOfProducts_ = 0;
		loadRecs();
	}

	void AidApp::pause()const {
		cout << "Press Enter to continue..." << endl;
		cin.ignore();
	}

	int AidApp::menu() {
		int choice;
		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "1- List products" << endl;
		cout << "2- Display product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to quantity of purchased products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";
		cin >> choice;
		cin.ignore(1000, '\n');
		if (choice < 0 || choice > 5)
		{
			choice = -1;
		}
		return choice;
	}
	// Not Complete
	void AidApp::loadRecs(){ // changable
		int readIndex = 0;
		char type;
		datafile_.open(filename_, std::ios::in);
		if (datafile_.fail())
		{
			datafile_.clear();
			datafile_.close();
			datafile_.open(filename_, std::ios::out);
			datafile_.close();
		}
		else
		{
			while (!datafile_.eof())
			{
				delete[] product_[readIndex];
				product_[readIndex] = nullptr;
				datafile_ >> type;
				if (datafile_.good())
				{
					switch (type)
					{
					case 'P':
						product_[readIndex] = new AmaPerishable();
						break;
					case 'N':
						product_[readIndex] = new AmaProduct();
						break;
					}
					datafile_.ignore();
					product_[readIndex]->load(datafile_);
					readIndex++;
				}
			}
		}
		noOfProducts_ = readIndex;
		datafile_.close();
	}
	void AidApp::saveRecs(){ //changable
		datafile_.open("aidapp.txt", std::ios::out);

			for (int i = 0; i < noOfProducts_; i++)
			{
				product_[i]->store(datafile_, false);
			}
			datafile_.close();

	}
	void AidApp::listProducts()const{
		double totalCost = 0;
		cout << endl;
		cout << " Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl;
		cout << "-----|--------|--------------------|-------|----|----------|----|----------" << endl;
		for (int i = 0; i < noOfProducts_; i++)
		{
			cout << setfill(' ') << setw(4) << right << i + 1 << " | ";
			product_[i]->write(cout, true);
				cout<< endl;
				totalCost += *product_[i];
			if (i == 9)
			{
				pause();
			}
			

		}
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Total cost of support: $" << setprecision(2) << fixed << totalCost;
	}
	int AidApp::SearchProducts(const char* sku)const{
		int ret = -1;
		for (int i = 0; i < noOfProducts_; i++)
		{
			if (*product_[i] == sku)
			{
				ret = i;
			}
		}
		return ret;
	}

	// Not Complete
	void AidApp::addQty(const char* sku){
		int index = SearchProducts(sku);
		int num;
		if (index == -1)
		{
			cout << "Not found!" << endl;
		}
		else
		{
			cout << "Please enter the number of purchased items: ";
			cin >> num;
			if (cin.fail())
			{
				cout << "Invalid quantity value!" << endl;
			}
			else
			{
				if (num < 1)
				{
					cout << "The number should be greater than 0";
					return;
				}
				int qtyNeeded = product_[index]->qtyNeeded();
				int qty = product_[index]->quantity();


				if (num > (qtyNeeded - qty))
				{
					cout << "Too many items; only " << (qtyNeeded - qty) << " is needed, please return the extra " << num - (qtyNeeded - qty) << " items." << endl;
				}
				else
				{
					product_[index]->operator+=(num);
					cin.ignore(1000, '\n');
				}
			       cout << endl  << "Updated!" << endl << endl;
			}
		}
		/*for (int i = 0; i < noOfProducts_; i++)
		{
			if (product_[i]->sku() == sku)
			{
				product_[i]->write(cout, false);
				
				cin >> num;
				if (cin.fail())
				{
					cout << "Invalid quantity value!" << endl;
				}
				if (!cin.fail())
				{
					if (product_[i]->qtyNeeded() < num)
					{
						product_[i]->quantity(num);
					}
				}
			}
			else
			{
				cout << "Not found!" << endl;
			}*/
		/*}*/
	}

	// Not Complete
	void AidApp::addProduct(bool Perishable){
		if (Perishable)
		{
			product_[noOfProducts_] = new AmaPerishable();
			product_[noOfProducts_]->read(cin);
			noOfProducts_++;
		}
		else
		{
			product_[noOfProducts_] = new AmaProduct();
			product_[noOfProducts_]->read(cin);
			noOfProducts_++;
		}
		saveRecs();
		cout << endl << "Product added" << endl << endl;
	}

	int AidApp::run(){
		char sku[MAX_SKU_LEN + 1];
		int num;
		int index;
		while ((num = menu()) != 0) {
			switch (num)
			{
			case 1:
				listProducts();
				cout << endl;
				cout << endl;
				pause();
				break;

			case 2:
				cout << endl << "Please enter the SKU: ";
				cin >> sku;
				cout << endl;
				index = SearchProducts(sku);
				if (index != -1)
				{
					product_[index]->write(cout, false);
				}
				else
				{
					cout << "Not found!" << endl;
				}
				cout << endl;
				cout << endl;
				pause();
				cout << endl;
				break;

			case 3:
				addProduct(false);
				break;

			case 4:
				cout << endl;
				addProduct(true);
				break;

			case 5:
				cout << endl;
				cout << "Please enter the SKU: ";
				cin >> sku;
				cout << endl ;
			//	addQty(sku);
				index = SearchProducts(sku);
				if (index != -1)
				{
					product_[index]->write(cout, false);
				}
				else
				{
					cout << "Not found!" << endl;
				}
				cout << endl;
				cout << endl;
				addQty(sku);
				break;
			default:
				cout << "===Invalid Selection, try again.===";
				pause();
				break;
			}
}

		
			cout << endl << "Goodbye!!" << endl;

return 0;
	}
}
