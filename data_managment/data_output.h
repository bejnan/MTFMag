/*
 * data_output.h
 *
 *  Created on: Apr 3, 2014
 *      Author: kuba
 */

#ifndef DATA_OUTPUT_H_
#define DATA_OUTPUT_H_

namespace Base {

/**
 * Interface for printing results
 */
class DataOutput {
 public:
  virtual ~DataOutput() {}
  virtual void PrintLine() = 0;
  virtual void PrintTitles() = 0;
};

} /* namespace Base */

#endif /* DATA_OUTPUT_H_ */
