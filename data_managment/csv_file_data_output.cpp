/*
 * CsvFileDataOutput.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: kuba
 */

#include "csv_file_data_output.h"

namespace Base {

CsvFileDataOutput::CsvFileDataOutput(string file_path) :
  FileDataOutput(file_path) {
}

CsvFileDataOutput::~CsvFileDataOutput() {
}

} /* namespace Base */
