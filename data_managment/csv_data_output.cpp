/*
 * CsvDataOutput.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: kuba
 */

#include "csv_data_output.h"

namespace Base {

CsvDataOutput::CsvDataOutput(char seperator)
    : SEPERATOR(seperator) {
}

void CsvDataOutput::PrintLine(vector<int>& results) {
  vector<int>::iterator result_iterator;

  for (result_iterator = results.begin(); result_iterator != results.end();
      result_iterator++) {
    GetOutputStream() << (*result_iterator) << SEPERATOR;
  }
  GetOutputStream() << "\n";
}

void CsvDataOutput::PrintTitles() {
  vector<string>::iterator titles_iterator;

  for (titles_iterator = titles_names_.begin();
      titles_iterator != titles_names_.end(); titles_iterator++) {
    GetOutputStream() << (*titles_iterator) << SEPERATOR;

  }
  GetOutputStream() << "\n";
}

CsvDataOutput::~CsvDataOutput() {

}

} /* namespace Base */
