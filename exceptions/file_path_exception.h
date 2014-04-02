/*
 * FilepathException.h
 *
 *  Created on: Feb 21, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef FILEPATHEXCEPTION_H_
#define FILEPATHEXCEPTION_H_

#include "data_provider_exception.h"

#include<string>

using std::string;

namespace Exception {

class FilePathException : public Exception::DataProviderException {
 public:
  FilePathException(string path="");
  virtual ~FilePathException();
  const char * what() const throw () {
    return message_.c_str();
  }
 private:
  string message_;
};

} /* namespace Exception */

#endif /* FILEPATHEXCEPTION_H_ */
