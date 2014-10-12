#include "utils.h"

namespace Utils {

string ToString(int number) {
  stringstream output_stream;
  output_stream << number;
  return output_stream.str();
}

string ToString(double number, int digits_after) {
  int ten_power = 1;
  int ten_power_counter = 0;
  while (ten_power < number) {
    ten_power *= 10;
    ten_power_counter++;
  }
  stringstream output_stream;
  output_stream << setprecision(digits_after + ten_power_counter) << number;
  return output_stream.str();
}

string ToString(double number) {
  return ToString(number,2);
}

} /* namespace Utils*/

