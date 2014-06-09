#ifndef INVALIDNAMEEXCEPTION_H_
#define INVALIDNAMEEXCEPTION_H_

#include "database_exception.h"

#include <string>

using std::string;

namespace Exception {

/**
 * Exception thrown when query to Database contains non-existing
 * name as parameter.
 * @see Base::Database::Query
 */
class InvalidNameException : public DatabaseException {
 public:
  /**
   * Constructor initialize exception message.
   * With given identifier message is more clear and
   * useful for debug.
   * @param search_name Non-existing name
   */
  InvalidNameException(string search_name = "");
  virtual ~InvalidNameException();

  const char * what() const throw () {
    return message_.c_str();
  }
 private:
  string message_;
};

} /* namespace Exception */

#endif /* INVALIDNAMEEXCEPTION_H_ */
