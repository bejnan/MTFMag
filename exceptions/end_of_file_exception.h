/*
 * EndOfFileException.h
 *
 *  Created on: Feb 21, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef ENDOFFILEEXCEPTION_H_
#define ENDOFFILEEXCEPTION_H_

#include "data_provider_exception.h"

namespace Exception {

class EndOfFileException : public Exception::DataProviderException {
 public:
  EndOfFileException();
  virtual ~EndOfFileException();
  const char * what() const throw () {
    return message_.c_str();
  }
 private:
  string message_;
};

} /* namespace Exception */

#endif /* ENDOFFILEEXCEPTION_H_ */
