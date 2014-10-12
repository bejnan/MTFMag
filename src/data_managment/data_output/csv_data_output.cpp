#include "csv_data_output.h"

namespace Base {

CsvDataOutput::CsvDataOutput(char seperator)
    : SEPARATOR(seperator) {
}

void CsvDataOutput::PrintLine(string line_to_print) {
  GetOutputStream() << line_to_print << "\n";
}

void CsvDataOutput::PrintResult(Result result) {
  GetOutputStream() << result.ToString() << SEPARATOR;
}

void CsvDataOutput::PrintColumnTitles() {
}

CsvDataOutput::~CsvDataOutput() {

}

} /* namespace Base */
