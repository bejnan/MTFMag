/*
 * CsvDataOutput.h
 *
 *  Created on: Apr 3, 2014
 *      Author: kuba
 */

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
 * Tool to write output data as csv file
 */
class CsvDataOutput : public virtual DataOutput {
 public:
  CsvDataOutput(char seperator = '|');
  virtual ~CsvDataOutput();
  virtual void PrintLine(vector<int>& results);
  virtual void PrintTitles();

 protected:
  using DataOutput::GetOutputStream;

 private:
  // names of titles of columns (algorithm names)
  vector<string> titles_names_;
  // separator of elements in file
  const char SEPERATOR;
};

} /* namespace Base */

#endif /* CSVDATAOUTPUT_H_ */
