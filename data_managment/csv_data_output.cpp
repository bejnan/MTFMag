/*
 * CsvDataOutput.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: kuba
 */

#include "csv_data_output.h"

namespace Base {

CsvDataOutput::CsvDataOutput()
    : SEPERATOR('|') {
}

CsvDataOutput::CsvDataOutput(string file_path)
    : SEPERATOR('|') {
  FileOutputStream* file_output_stream = new FileOutputStream(file_path);
  file_output_stream_ptr_ = shared_ptr<FileOutputStream>(file_output_stream);
}

void CsvDataOutput::PrintLine(vector<int>& results) {
  vector<int>::iterator result_iterator;

  for (result_iterator = results.begin(); result_iterator != results.end();
      result_iterator++) {
    if (file_output_stream_ptr_) {
      (*file_output_stream_ptr_) << (*result_iterator) << SEPERATOR;
    } else {
      cout << (*result_iterator) << SEPERATOR;
    }
  }

  if (file_output_stream_ptr_) {
    (*file_output_stream_ptr_) << "\n";
  } else {
    cout << "\n";
  }
}

void CsvDataOutput::PrintTitles() {
  vector<string>::iterator titles_iterator;

  for (titles_iterator = titles_names_.begin();
      titles_iterator != titles_names_.end(); titles_iterator++) {
    if (file_output_stream_ptr_) {
      (*file_output_stream_ptr_) << (*titles_iterator) << SEPERATOR;
    } else {
      cout << (*titles_iterator) << SEPERATOR;
    }
  }

  if (file_output_stream_ptr_) {
    (*file_output_stream_ptr_) << "\n";
  } else {
    cout << "\n";
  }
}

CsvDataOutput::~CsvDataOutput() {

}

} /* namespace Base */
