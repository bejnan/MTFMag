#ifndef DATAPROVIDER_H_
#define DATAPROVIDER_H_

#include <string>

using std::string;

namespace Base {
/**
 * Interface for data providers. Data provider should
 * return single line of input containing all elements :
 * - type of interaction
 * - timestamp
 * - sender id
 * - receiver id
 *
 * It is important to give access to single line multiple times (for multiple objects)
 */
class DataProvider {
 public :
  virtual ~DataProvider() {}
  virtual string GetActualLine() = 0;
  virtual string GetLineBefore() = 0;
  virtual void GoToNextLine() = 0;
};

}

#endif
