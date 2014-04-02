/*
 * DataProviderException.h
 *
 *  Created on: Feb 21, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef DATAPROVIDEREXCEPTION_H_
#define DATAPROVIDEREXCEPTION_H_

#include <exception>
#include <string>

using std::string;
namespace Exception {

class DataProviderException : public std::exception {
 public:
  DataProviderException();
  virtual ~DataProviderException();
  const char * what() const throw () {
    return message_.c_str();
  }
 private:
  string message_;
};

} /* namespace Exception */

#endif /* DATAPROVIDEREXCEPTION_H_ */
