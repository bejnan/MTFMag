/*
 * FileDataProvider.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "FileDataProvider.h"

namespace Base {

FileDataProvider::FileDataProvider(string file_path)
    : file_path_(file_path),
      actual_line_(""),
      line_before_("") {
  input_file_ = fopen(file_path_.c_str(), "rt");
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
    throw "End of File";
  }
}

} /* namespace Tree */
