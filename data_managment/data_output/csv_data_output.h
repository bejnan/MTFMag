#ifndef CSVDATAOUTPUT_H_
#define CSVDATAOUTPUT_H_

#include "data_output.h"

#include <vector>
#include <iostream>
#include <memory>

using std::vector;
using std::string;
using std::cout;
using std::shared_ptr;

namespace Base {

/**
 * Printer of output in CSV format.
 * Virtual inheritance used to enable multiple inheritance
 * by child classes @see CsvFileDataOutput
 * @author Jakub Banaszewski
 */
class CsvDataOutput : public virtual DataOutput {
 public:

  /**
   * Constructor setting default values of class values
   * @param separator Char to separate columns of data
   */
  CsvDataOutput(char separator = '|');

  /**
   * Default destructor
   */
  virtual ~CsvDataOutput();

  virtual void PrintLine(int turns_count, vector<int> results);

  virtual void PrintColumnTitles();

  virtual void SetColumnTitles(vector<string> titles);

  virtual bool AreTitlesPrinted() {
    return are_titles_printed_;
  }

 protected:
  using DataOutput::GetOutputStream;

 private:
  vector<string> titles_names_; /**< names of titles of columns
                                   (algorithm names) */
  bool are_titles_printed_; /**< Bool to remember decision
                                 if PrintColumnTitles was used*/
  const char SEPARATOR;     /**< Separator of result columns */
};

} /* namespace Base */

#endif /* CSVDATAOUTPUT_H_ */
