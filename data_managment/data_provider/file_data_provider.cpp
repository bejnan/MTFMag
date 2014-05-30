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

string FileDataProvider::GetActualLine() {
  return actual_line_;
}

string FileDataProvider::GetLineBefore() {
  return line_before_;
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
