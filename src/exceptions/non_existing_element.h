#ifndef NON_EXISTING_ELEMENT_H_
#define NON_EXISTING_ELEMENT_H_

#include <exception>
#include <string>

#include "../utils/utils.h"

using std::string;
using std::exception;

namespace Exception {

class NonExistingElement : public std::exception {
 public:
  NonExistingElement(int id  = 0);
  virtual ~NonExistingElement();

  const char * what() const throw () {
      return message_.c_str();
    }
   private:
    string message_;
};

} /* namespace Exception */

#endif /* NON_EXISTING_ELEMENT_H_ */
