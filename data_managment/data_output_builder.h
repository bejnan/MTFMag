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
 * Generates DataOutput instances.
 * This class should be replace by another mechanism.
 */
class DataOutputBuilder {
 public:

  /**
   * Default destructor (nothing to handle)
   */
  virtual ~DataOutputBuilder();

  /**
   * Creates pointer to DataOutputBuilder.
   * @return Fresh instance of DataOutputBuilder with default settings
   */
  static shared_ptr<DataOutputBuilder> GetInstance();

  /**
   * Generated DataOutput will use file as output (be instance of
   * FileDataOuput class)
   * @param file_path Path to file
   * @return Reference used to DataOutputBuilder
   * @see FileDataOutput
   */
  DataOutputBuilder& UseFile(string file_path);

  /**
   * Generated DataOutput will use CSV output format (be instance if
   * CsvDataOutput class)
   * @param separator Separator between columns
   * @return Reference to DataOutputBuilder
   * @see CsvDataOutput
   */
  DataOutputBuilder& SetCsvOutputFormat(char separator);

  /**
   * Generates DataOutput with chosen features
   * @return DataOutput pointer. Instance of DataOutput depends of
   * class setting.
   * @see DataOutput
   * @see CsvDataOutput
   * @see CsvFileDataOutput
   */
  shared_ptr<DataOutput> Generate();

 private:
  /**
   * Default constructor used only by GetInstance method
   */
  DataOutputBuilder();

  string file_path_;    /**< Path of output file for generated DataOutput */
  bool use_file_;       /**< Remember if UseFile method was used */
  char separator_;      /**< Separator for instance of CsvDataOutput*/
  bool use_csv_format_; /**< Remember if SetCsvOutputFormat method was used */
};

} /* namespace Base */

#endif /* DATA_OUTPUT_BUILDER_H_ */
