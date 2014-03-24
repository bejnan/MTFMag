/*
 * MatrixMTFProcessorFactory.h
 *
 *  Created on: Mar 22, 2014
 *      Author: kuba
 */

#ifndef MATRIXMTFPROCESSORFACTORY_H_
#define MATRIXMTFPROCESSORFACTORY_H_

#include "ProcessorFactory.h"
#include "MatrixMTFProcessor.h"

#include <string>
using std::to_string;

namespace Tools {

class MatrixMTFProcessorFactory : public Tools::ProcessorFactory{
 public:
  MatrixMTFProcessorFactory(int matrix_width = 2);
  virtual ~MatrixMTFProcessorFactory();
  virtual shared_ptr<Processor> GenerateProcessor(int user_id);
 private:
   string algorithm_name_;
   int matrix_width_;
};

} /* namespace Tools */

#endif /* MATRIXMTFPROCESSORFACTORY_H_ */
