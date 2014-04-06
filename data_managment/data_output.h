/*
 * data_output.h
 *
 *  Created on: Apr 3, 2014
 *      Author: kuba
 */

#ifndef DATA_OUTPUT_H_
#define DATA_OUTPUT_H_

#include <vector>

using std::vector;

namespace Base {

/**
 * Interface for printing results
 */
class DataOutput {
 public:
  virtual ~DataOutput() {
  }
  // print verse of results
  virtual void PrintLine(vector<int>& results) = 0;
  // print titles of columns
  virtual void PrintTitles() = 0;
};

} /* namespace Base */

#endif /* DATA_OUTPUT_H_ */
