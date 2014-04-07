/*
 * file_data_output.h
 *
 *  Created on: Apr 7, 2014
 *      Author: kuba
 */

#ifndef FILE_DATA_OUTPUT_H_
#define FILE_DATA_OUTPUT_H_

#include "data_output.h"

#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::ofstream;
using std::ostream;

namespace Base {

/**
 * Role of this class is to provide output stream which write to file and
 * take care of it.
 */

class FileDataOutput : public virtual Base::DataOutput {
 public:
  FileDataOutput(string file_path);
  virtual ~FileDataOutput();
 protected:
  virtual ostream& GetOutputStream();

 private:
  ofstream output_file_stream_;
};

} /* namespace Base */

#endif /* FILE_DATA_OUTPUT_H_ */
