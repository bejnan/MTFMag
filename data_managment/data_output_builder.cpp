/*
 * data_output_builder.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: kuba
 */

#include "data_output_builder.h"

namespace Base {

DataOutputBuilder::DataOutputBuilder()
    : file_path_(""),
      use_file_(false),
      separator_(' '),
      use_csv_format_(false) {
}

DataOutputBuilder::~DataOutputBuilder() {
}

shared_ptr<DataOutputBuilder> DataOutputBuilder::GetInstance() {
  DataOutputBuilder* new_builder = new DataOutputBuilder();
  return shared_ptr<DataOutputBuilder>(new_builder);
}

DataOutputBuilder& DataOutputBuilder::UseFile(string file_path) {
  use_file_ = true;
  file_path_ = file_path;
  return *this;
}

DataOutputBuilder& DataOutputBuilder::SetCsvOutputFormat(char separator) {
  use_csv_format_ = true;
  separator_ = separator;
  return *this;
}
// TODO Quite ugly solution. Better use inheritance
shared_ptr<DataOutput> DataOutputBuilder::Generate() {
  DataOutput* new_data_output;
  if (use_csv_format_) {
    if (use_file_) {
      new_data_output = new CsvFileDataOutput(file_path_, separator_);
    } else {
      new_data_output = new CsvDataOutput(separator_);
    }
  }
  return shared_ptr<DataOutput>(new_data_output);
}

} /* namespace Base */
