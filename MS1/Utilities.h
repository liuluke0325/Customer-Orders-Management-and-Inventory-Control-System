#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H
#include <iostream>

namespace sict {
	//The Utilities module is a support module that contains the functionality that is common across the system.

	class Utilities {

		static size_t width; // // for "all" object of this class
		static char delimiter; // for "all" object of this class


	public:
		/*A default constructor that places the object in a safe empty state and initializes its field
width to a size that is less than the possible size of any token.?????????*/
		Utilities() {};
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		static void setFieldWidth(size_t);
	};


}//!sict





#endif // !SICT_UTILITIES_H
