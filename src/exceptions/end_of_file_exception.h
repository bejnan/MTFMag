#ifndef ENDOFFILEEXCEPTION_H_
#define ENDOFFILEEXCEPTION_H_

#include "data_provider_exception.h"

namespace Exception {

/**
 * Exception is thrown when DataProvider meets end of input
 * and program is trying to get next line of data.
 * @see Base::DataProvider::GoToNextLine
 */
class EndOfFileException : public Exception::DataProviderException {
 public:
  EndOfFileException();
  const char * what() const throw () {
    return message_.c_str();
  }
 private:
  string message_;
};

} /* namespace Exception */

#endif /* ENDOFFILEEXCEPTION_H_ */
