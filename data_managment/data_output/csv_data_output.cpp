#include "csv_data_output.h"

namespace Base {

CsvDataOutput::CsvDataOutput(char seperator)
    : SEPARATOR(seperator) {
}

void CsvDataOutput::PrintLine(int turns_count, vector<string> results) {
  vector<string>::iterator result_iterator;
  GetOutputStream() << turns_count << SEPARATOR;

  for (result_iterator = results.begin(); result_iterator != results.end();
      result_iterator++) {
    GetOutputStream() << (*result_iterator) << SEPARATOR;
  }
  GetOutputStream() << "\n";
}

void CsvDataOutput::PrintColumnTitles() {
}

CsvDataOutput::~CsvDataOutput() {

}

} /* namespace Base */
