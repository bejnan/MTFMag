/*
 * FileDataProvider.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "file_data_provider.h"
#include "../../headers/exceptions.h"

namespace Base {

FileDataProvider::FileDataProvider(string file_path)
    : file_path_(file_path),
      actual_line_(""),
      line_before_("") {
  input_file_ = fopen(file_path_.c_str(), "rt");
  if (!input_file_)
    throw Exception::FilePathException(file_path);
}

FileDataProvider::~FileDataProvider() {
  fclose(input_file_);
}

const DataProvider::DataInputLine FileDataProvider::GetActualLine() {
  int interaction, timestamp, sender_id, receiver_id;
  stringstream input_line_stream;
  input_line_stream.str(actual_line_);
  input_line_stream >> interaction >> timestamp >> sender_id >> receiver_id;
  DataProvider::DataInputLine actual_line_data(interaction, timestamp,
                                                sender_id, receiver_id);
  return actual_line_data;
}

const DataProvider::DataInputLine FileDataProvider::GetLineBefore() {
  int interaction, timestamp, sender_id, receiver_id;
  stringstream input_line_stream;
  input_line_stream.str(line_before_);
  input_line_stream >> interaction >> timestamp >> sender_id >> receiver_id;
  DataProvider::DataInputLine line_before_data(interaction, timestamp,
                                                sender_id, receiver_id);
  return line_before_data;
}

void FileDataProvider::GoToNextLine() {
  char new_actual_line[100];
  if (fgets(new_actual_line, 100, input_file_) != NULL) {
    line_before_ = actual_line_;
    actual_line_ = string(new_actual_line);
  } else {
    throw Exception::EndOfFileException();
  }
}

} /* namespace Tree */
