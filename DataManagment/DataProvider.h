#ifndef DATAPROVIDER_H_
#define DATAPROVIDER_H_

#include <string>

using std::string;

namespace Base {

class DataProvider {
 public :
  virtual ~DataProvider() {}
  virtual string GetActualLine() = 0;
  virtual string GetLineBefore() = 0;
  virtual void GoToNextLine() = 0;
};

}

#endif
