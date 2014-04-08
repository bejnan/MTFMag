/*
 * CsvDataOutput.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: kuba
 */

#include "csv_data_output.h"

namespace Base {

CsvDataOutput::CsvDataOutput(char seperator)
    : are_titles_printed_(false),
      SEPERATOR(seperator) {
}

void CsvDataOutput::PrintLine(int turns_count, vector<int> results) {
  vector<int>::iterator result_iterator;
  GetOutputStream() << turns_count << SEPERATOR;

  for (result_iterator = results.begin(); result_iterator != results.end();
      result_iterator++) {
    GetOutputStream() << (*result_iterator) << SEPERATOR;
  }
  GetOutputStream() << "\n";
}

void CsvDataOutput::PrintColumnTitles() {
  vector<string>::iterator titles_iterator;
  GetOutputStream() << "Turns" << SEPERATOR;

  for (titles_iterator = titles_names_.begin();
      titles_iterator != titles_names_.end(); titles_iterator++) {
    GetOutputStream() << (*titles_iterator) << SEPERATOR;

  }
  GetOutputStream() << "\n";
  are_titles_printed_ = true;
}

void CsvDataOutput::SetColumnTitles(vector<string> titles) {
  titles_names_ = titles;
}

CsvDataOutput::~CsvDataOutput() {

}

} /* namespace Base */
