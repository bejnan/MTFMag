/*
 * InvalidIndexException.h
 *
 *  Created on: Feb 20, 2014
 *      Author: kuba
 */

#ifndef INVALIDINDEXEXCEPTION_H_
#define INVALIDINDEXEXCEPTION_H_

#include <exception>

using std::exception;
using std::string;

namespace Exception {

class InvalidIndexException : public exception {
 public:
  InvalidIndexException(int id = -1);
  virtual ~InvalidIndexException();

  const char * what() const throw () {
    return message_.c_str();
  }

 private :
  const int id_;
  string message_;
};

} /* namespace Exception */

#endif /* INVALIDINDEXEXCEPTION_H_ */
