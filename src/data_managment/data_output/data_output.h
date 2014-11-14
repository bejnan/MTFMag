
#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "../../results/results.h"

using std::ostream;
using std::vector;
using std::cout;
using std::string;

namespace Base {

/**
 * Interface for printing results. Used in DataCollector for
 * creating output of tested algorithms.
 * @see DataCollector::PrintResults
 * @see DataCollector::PrintResultsFromPointers
 */
class DataOutput {
 public:

  virtual ~DataOutput() {  }

  virtual void PrintLine(string) = 0;
  virtual void PrintResult(Result) = 0;

  virtual void PrintColumnTitles() = 0;

 protected:
  virtual ostream& GetOutputStream() {
    return cout;
  }
};

} /* namespace Base */
