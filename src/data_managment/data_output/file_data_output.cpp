/*
 * file_data_output.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: kuba
 */

#include "file_data_output.h"

namespace Base {

FileDataOutput::FileDataOutput(string file_path)
    : output_file_stream_(file_path) {

}

FileDataOutput::~FileDataOutput() {
  output_file_stream_.close();
}

ostream& FileDataOutput::GetOutputStream() {
  return output_file_stream_;
}

} /* namespace Base */
