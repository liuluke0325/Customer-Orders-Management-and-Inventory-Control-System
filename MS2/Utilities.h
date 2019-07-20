/*
Hsueh Chih Liu
116131186
07/19/2019
MS2
*/


#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H
#include <iostream>

namespace sict {
	//The Utilities module is a support module that contains the functionality that is common across the system.

	class Utilities {

		static size_t width; // // for "all" object of this class
		static char delimiter; // for "all" object of this class


	public:

		Utilities() {};
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		static void setFieldWidth(size_t);
	};


}//!sict





#endif // !SICT_UTILITIES_H
