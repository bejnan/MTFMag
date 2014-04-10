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
   * @param results       Vector of
   */
  virtual void PrintLine(int turns_count, vector<int> results) = 0;

  /**
   * Print titles of columns
   */
  virtual void PrintColumnTitles() = 0;

  /**
   * Setter for titles_names_
   * @param titles Titles which replaces titles_names_
   */
  virtual void SetColumnTitles(vector<string> titles) = 0;

  /**
   * Getter for are_titles_printed
   * @return True if method PrintColumnTitles() was used before, false otherwise
   */
  virtual bool AreTitlesPrinted() = 0;

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
