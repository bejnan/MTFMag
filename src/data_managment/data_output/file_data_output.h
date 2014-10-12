#pragma once

#include "data_output.h"

#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::ostream;
using std::ofstream;

namespace Base {

/**
 * Role of this virtual class (not all methods are implemented) is to provide output stream which write to file and
 * take care of it.
 * It doesn't provide implementation for print methods from DataOutput
 * @see DataOutput
 */

class FileDataOutput : public virtual DataOutput {
 public:
  /**
   * Contructor opens file and stream for output.
   * Parameter is needed to point file to open or create.
   * @param file_path Path to output file
   */
  FileDataOutput(string file_path);

  /**
   * Destructor closes stream and file.
   */
  virtual ~FileDataOutput();
 protected:

  /**
   * The only implemented method in this class. It provides every child class ready
   * stream to write to file.
   * @return Stream which put output in file from given path.
   */
  virtual ostream& GetOutputStream();

 private:
  /**
   * File stream opened in constructor for output;
   * GetOutputStream is getter of that property;
   */
  ofstream output_file_stream_;
};

} /* namespace Base */
