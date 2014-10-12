#ifndef DATAPROVIDEREXCEPTION_H_
#define DATAPROVIDEREXCEPTION_H_

#include <exception>
#include <string>

using std::string;
namespace Exception {

/**
 * Base class for exceptions which occurs during providing data
 * from DataProvider to DataCollector
 * @see Base::DataCollector
 */
class DataProviderException : public std::exception {
 public:
  DataProviderException();
  const char * what() const throw () {
    return message_.c_str();
  }
 private:
  string message_;
};

} /* namespace Exception */

#endif /* DATAPROVIDEREXCEPTION_H_ */
