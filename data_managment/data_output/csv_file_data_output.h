#ifndef CSVFILEDATAOUTPUT_H_
#define CSVFILEDATAOUTPUT_H_

#include "csv_data_output.h"
#include "file_data_output.h"

namespace Base {

/**
 * Class to produce output in output file in format CSV.
 * It has two parent class from which it uses methods.
 * It doesn't have any own method except from contructor.
 */
class CsvFileDataOutput : public Base::FileDataOutput,
    public Base::CsvDataOutput {
 public:
  /**
   * Constructor with parameters for parent classes.
   * @param file_path Needed for FileDataOutput
   * @param separator Needed for CsvDataOutput
   */
  CsvFileDataOutput(string file_path, char separator='|');
  ~CsvFileDataOutput();
  using CsvDataOutput::PrintLine;
  using CsvDataOutput::PrintColumnTitles;
 protected:
  using FileDataOutput::GetOutputStream;

};

} /* namespace Base */

#endif /* CSVFILEDATAOUTPUT_H_ */
