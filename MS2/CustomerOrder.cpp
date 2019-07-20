/*
Hsueh Chih Liu
116131186
07/19/2019
MS2
*/

#include "CustomerOrder.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
namespace sict {
	size_t CustomerOrder::width = 0;
	CustomerOrder::CustomerOrder(const string& src) {
		//This constructor extracts no less than 3 tokens from the string.
		vector<string> token;

		for (size_t nextPos = 0; nextPos < src.size(); )
		{
			token.push_back(utilities.extractToken(src, nextPos));
		}

		//throw error when there are less than 3 token in the string
		if (token.size() < 3)
		{
			throw (string)"no items have been requested to be added";
		}


		//save the data
		this->customerName = token[0];
		this->productName = token[1];


		//allocate the memory for all need items
		ptrItemInfo = new ItemInfo[token.size() - 2];

		for (size_t i = 2; i < token.size(); i++)
		{
			//store item start from index 0
			ptrItemInfo[i - 2].name = token[i];
			this->itemInfoCounter++;
		}

		//determines the field width
		this->width = utilities.getFieldWidth();

	}

	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
		//checks each item request

		for (size_t i = 0; i < this->itemInfoCounter; i++)
		{


			// if the name are the same
			if (item.getName().compare(this->ptrItemInfo[i].name) == 0)
			{
				//save the serial number




				//check if the request is available and the request has not been filled
				if ((item.getQuantity() > 0) && !this->ptrItemInfo[i].filled)
				{
					//save serial number and fill it
					this->ptrItemInfo[i].serialNumber = item.getSerialNumber();
					this->ptrItemInfo[i].filled = true;
					os << " Filled " << getNameProduct();
					item.display(os, false);
					//--item; // change the item quantity ???
				}
				else if (item.getQuantity() == 0 && !this->ptrItemInfo[i].filled) {
					os << " Unable to fill " << getNameProduct();
					item.display(os, false);
					os << " out of stock";
				}
				else if (item.getQuantity() > 0 && this->ptrItemInfo[i].filled) {
					os << " Unable to fill " << getNameProduct();
					item.display(os, false);
					os << " already filled";
				}


				os << endl;

			}

		}
	}

	CustomerOrder::~CustomerOrder() {
		delete[] ptrItemInfo;

	}

	bool CustomerOrder::isFilled() const {

		bool allfilled = true;// assume all is filled

		for (size_t i = 0; i < this->itemInfoCounter; i++)
		{
			if (this->ptrItemInfo[i].filled == false)
			{
				allfilled = false; // if any is not filled, return false
			}
		}

		return allfilled;

	}


	bool CustomerOrder::isItemFilled(const std::string& item) const {
		bool itemFilled = true; // assume that item is true
		// If the item is not in the request list, this function returns true.


		for (size_t i = 0; i < this->itemInfoCounter; i++)
		{
			if (item.compare(this->ptrItemInfo[i].name) == 0) //  find if two name are same
			{
				if (!ptrItemInfo[i].filled) // if is not filled
				{
					itemFilled = false;
				}
			}

		}


		return itemFilled;


	}

	string CustomerOrder::getNameProduct() const {

		string str = this->customerName;

		for (size_t i = customerName.size(); i < this->width; i++)
		{
			//add the space
			str += " ";
		}
		return str + " [" + this->productName + "]";

	}

	void CustomerOrder::display(std::ostream& os, bool showDetail) const {

		cout << getNameProduct() << endl;


		for (size_t i = 0; i < this->itemInfoCounter; i++)
		{

			if (showDetail)
			{
				cout << setw(this->width + 1) << " " << "[" << this->ptrItemInfo[i].serialNumber << "]";
				cout << this->ptrItemInfo[i].name << "_";
				cout << (this->ptrItemInfo[i].filled == true ? "Filled" : "UnFilled") << endl;
			}
			else {
				cout << setw(this->width + 1) << " " << this->ptrItemInfo[i].name << endl;

			}

		}




	}







	CustomerOrder::CustomerOrder() {}

	CustomerOrder& CustomerOrder::operator = (CustomerOrder&& src) noexcept {

		//delete current
		delete[] this->ptrItemInfo;

		//copy

		this->customerName = src.customerName;
		this->productName = src.productName;
		this->itemInfoCounter = src.itemInfoCounter;
		this->ptrItemInfo = new ItemInfo[itemInfoCounter];
		this->width = src.width;


		for (size_t i = 0; i < itemInfoCounter; i++)
		{
			this->ptrItemInfo[i] = src.ptrItemInfo[i];
		}

		//delete src
		delete[] src.ptrItemInfo;


		//move the src
		src.customerName.clear();
		src.productName.clear();
		src.itemInfoCounter = 0u;
		src.ptrItemInfo = nullptr;


		return *this;
	}


	CustomerOrder::CustomerOrder(CustomerOrder&& src) {
		this->ptrItemInfo = nullptr;
		*this = move(src);
	}

} //!sict


