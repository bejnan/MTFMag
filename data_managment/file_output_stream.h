/*
 * file_output_stream.h
 *
 *  Created on: Apr 6, 2014
 *      Author: kuba
 */

#ifndef FILE_OUTPUT_STREAM_H_
#define FILE_OUTPUT_STREAM_H_

#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::ofstream;
using std::ostream;
namespace Base {

/**
 * Role of this class is to provide output stream and
 * take care of it.
 */
class FileOutputStream {
 public:
  FileOutputStream(string output_file_path);
  virtual ~FileOutputStream();

  // insertion to stream operator overload to simplify use of class
  template<typename T>
  ostream& operator<<(T object_to_write) {
    output_file_stream_ << object_to_write;
    return output_file_stream_;
  }

 private:
  ofstream output_file_stream_;
};

} /* namespace Base */

#endif /* FILE_OUTPUT_STREAM_H_ */
