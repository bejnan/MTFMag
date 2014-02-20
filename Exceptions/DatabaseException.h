/*
 * DatabaseException.h
 *
 *  Created on: Feb 20, 2014
 *      Author: kuba
 */

#ifndef DATABASEEXCEPTION_H_
#define DATABASEEXCEPTION_H_

#include <exception>

namespace Base {

class DatabaseException : public std::exception {
 public:
  DatabaseException();
  virtual ~DatabaseException();

 private:

};

} /* namespace Base */

#endif /* DATABASEEXCEPTION_H_ */
