/*
 * data_output.h
 *
 *  Created on: Apr 3, 2014
 *      Author: kuba
 */

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
 * Interface for printing results
 */
class DataOutput {
 public:
  virtual ~DataOutput() { }
  // print verse of results
  virtual void PrintLine(int turns_count, vector<int> results) = 0;
  // print titles of columns
  virtual void PrintColumnTitles() = 0;
  // set titles of columns
  virtual void SetColumnTitles(vector<string> titles) = 0;
  // check if column titles are printed
  virtual bool AreTitlesPrinted() = 0;

 protected:
  // method return stream to write to
  virtual ostream& GetOutputStream() { return cout; }
  ;
};

} /* namespace Base */

#endif /* DATA_OUTPUT_H_ */
