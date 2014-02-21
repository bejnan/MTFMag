/*
 * FilepathException.h
 *
 *  Created on: Feb 21, 2014
 *      Author: kuba
 */

#ifndef FILEPATHEXCEPTION_H_
#define FILEPATHEXCEPTION_H_

#include "DataProviderException.h"

#include<string>

using std::string;

namespace Exception {

class FilepathException : public Exception::DataProviderException {
 public:
  FilepathException(string path="");
  virtual ~FilepathException();
  const char * what() const throw () {
    return message_.c_str();
  }
 private:
  string message_;
};

} /* namespace Exception */

#endif /* FILEPATHEXCEPTION_H_ */
