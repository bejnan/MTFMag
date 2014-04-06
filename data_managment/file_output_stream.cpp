/*
 * file_output_stream.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: kuba
 */

#include "file_output_stream.h"

namespace Base {

FileOutputStream::FileOutputStream(string output_file_path)
    : output_file_stream_(output_file_path) {
}

FileOutputStream::~FileOutputStream() {
  output_file_stream_.close();
}

} /* namespace Base */
