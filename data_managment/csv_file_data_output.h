/*
 * CsvFileDataOutput.h
 *
 *  Created on: Apr 7, 2014
 *      Author: kuba
 */

#ifndef CSVFILEDATAOUTPUT_H_
#define CSVFILEDATAOUTPUT_H_

#include "csv_data_output.h"
#include "file_data_output.h"

namespace Base {

class CsvFileDataOutput : public Base::FileDataOutput,
    public Base::CsvDataOutput {
 public:
  CsvFileDataOutput(string file_path, char seperator='|');
  ~CsvFileDataOutput();
  using CsvDataOutput::PrintLine;
  using CsvDataOutput::PrintTitles;

 protected:
  using FileDataOutput::GetOutputStream;

};

} /* namespace Base */

#endif /* CSVFILEDATAOUTPUT_H_ */
