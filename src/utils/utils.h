#include <string>
#include <sstream>
#include <iomanip>

using std::stringstream;
using std::string;
using std::setprecision;

namespace Utils {

/**
 * Method to generate string from number
 * @param number Number smaller than 1000000000
 * @return string representing number
 */
string ToString(int number);

/**
 * Method to generate string from decimal
 * @param number decimal to convert
 * @param precision number of digits after dot
 * @return string representing number
 */
string ToString(double number, int precision);


/**
 * Method to generate string from decimal with default 2 digits after
 * dot
 * @param number decimal to convert
 * @return string representing number
 */
string ToString(double number);

} /* namespace Utils */

