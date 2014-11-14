#pragma once

#include "database_exception.h"

#include <exception>
#include <string>

#include "../utils/utils.h"

using std::exception;
using std::string;

namespace Exception {

/**
 * Exception thrown when query to Database contains non-existing
 * identifier.
 * @see Base::Database::Query
 */
class InvalidIndexException : public DatabaseException{
 public:
  /**
   * Constructor initialize exception message.
   * With given identifier message is more clear and
   * useful for debug.
   * @param id Non-existing identifier
   */
  InvalidIndexException(int id = -1);

  const char * what() const throw () {
    return message_.c_str();
  }

 private :
  const int id_;
  string message_;
};

} /* namespace Exception */

