/*
 * data_output_builder.h
 *
 *  Created on: Apr 7, 2014
 *      Author: kuba
 */

#ifndef DATA_OUTPUT_BUILDER_H_
#define DATA_OUTPUT_BUILDER_H_

#include "data_output.h"
#include "csv_data_output.h"
#include "csv_file_data_output.h"

#include <memory>
#include <string>

using std::shared_ptr;
using std::string;

namespace Base {

/**
 * Class generating DataOutput instances using Build pattern.
 */
class DataOutputBuilder {
 public:
  virtual ~DataOutputBuilder();

  static shared_ptr<DataOutputBuilder> GetInstance();
  // Set builder to generate data output with file output
  DataOutputBuilder& UseFile(string file_path);
  // Set builder to generate data output in csv format
  DataOutputBuilder& SetCsvOutputFormat(char seperator);
  // Method to generate appropriate instance of DataOutput
  shared_ptr<DataOutput> Generate();

 private:
  DataOutputBuilder();
  string file_path_;
  bool use_file_;
  char seperator_;
  bool use_csv_format_;
};

} /* namespace Base */

#endif /* DATA_OUTPUT_BUILDER_H_ */
