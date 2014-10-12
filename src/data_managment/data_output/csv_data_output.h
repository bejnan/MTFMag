
#pragma once

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

  virtual ~CsvDataOutput();

  virtual void PrintLine(string);
  virtual void PrintResult(Result);
  virtual void PrintColumnTitles();

 protected:
  using DataOutput::GetOutputStream;

 private:
  const char SEPARATOR; /**< Separator of result columns */
};

} /* namespace Base */

