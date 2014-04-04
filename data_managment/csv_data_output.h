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
#include <string>
#include <ostream>

using std::vector;
using std::string;
using std::ostream;
using std::cout;

namespace Base {

class CsvDataOutput : public DataOutput {
 public:
  CsvDataOutput(ostream& output = cout);
  virtual ~CsvDataOutput();
  virtual void PrintLine();
  virtual void PrintTitles();
 private :
  vector<string> titles_names;
  ostream& output_stream;
};

} /* namespace Base */

#endif /* CSVDATAOUTPUT_H_ */
