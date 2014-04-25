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

/**
 * Exception is thrown when bad file path is given to DataProvider instance.
 * @see Base::FileDataProvider
 */
class FilePathException : public Exception::DataProviderException {
 public:
  /**
   * In constructor bad file path should be given to get better exception message.
   * @param path Path to non-existing file, that cause exception
   */
  FilePathException(string path = "");
  virtual ~FilePathException();
  const char * what() const throw () {
    return message_.c_str();
  }
 private:
  string message_;
};

} /* namespace Exception */

#endif /* FILEPATHEXCEPTION_H_ */
