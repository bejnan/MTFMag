#ifndef DATA_OUTPUT_H_
#define DATA_OUTPUT_H_

#include <vector>
#include <iostream>
#include <string>

using std::ostream;
using std::vector;
using std::cout;
using std::string;

namespace Base {

/**
 * Interface for printing results. Used in DataCollector for
 * creating output of tested algorithms.
 */
class DataOutput {
 public:

  /**
   * Empty destructor
   */
  virtual ~DataOutput() {  }

  /**
   * Print single line of results.
   * @param turns_count   First column of output, number of passed turns(tests)
   * @param results       Vector of results
   */
  virtual void PrintLine(int turns_count, vector<string> results) = 0;

  /**
   * Print titles of columns
   */
  virtual void PrintColumnTitles() = 0;

 protected:
  /**
   * Method to get stream for output. It is used only by delivery classes.
   * @return Default stream is standard output stream
   */
  virtual ostream& GetOutputStream() {
    return cout;
  }
};

} /* namespace Base */

#endif /* DATA_OUTPUT_H_ */
