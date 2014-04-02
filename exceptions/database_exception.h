/*
 * DatabaseException.h
 *
 *  Created on: Feb 20, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef DATABASEEXCEPTION_H_
#define DATABASEEXCEPTION_H_

#include <exception>
#include <string>

using std::string;
using std::exception;

namespace Exception {

class DatabaseException : public exception {
 public:
  DatabaseException();
  virtual ~DatabaseException();

  const char * what() const throw() {
	  return message_.c_str();
  }
 private:
  string message_;

};

} /* namespace Base */

#endif /* DATABASEEXCEPTION_H_ */
