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
  /**
   * Empty destuctor
   */
  virtual ~DataProvider() {}

  /**
   * Returns string with reading of actual input line.
   * @return Every string should contain line with 4 numbers
   * separated by whitespace
   */
  virtual string GetActualLine() = 0;

  /**
   * Returns string with reading of input line before
   * @return Every string should contain line with 4 numbers
   * separated by whitespace
   */
  virtual string GetLineBefore() = 0;

  /**
   * Switches reading to next input line.
   * Line before should be set to actual line (before reading)
   */
  virtual void GoToNextLine() = 0;
};

}

#endif
