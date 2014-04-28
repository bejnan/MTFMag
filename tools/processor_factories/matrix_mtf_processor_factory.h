/*
 * MatrixMTFProcessorFactory.h
 *
 *  Created on: Mar 22, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef MATRIXMTFPROCESSORFACTORY_H_
#define MATRIXMTFPROCESSORFACTORY_H_

#include "../processor_factory.h"
#include "../../headers/algorithms.h"
#include "../../headers/elements.h"
#include "../judges.h"

namespace Tools {

/**
 * Generator of MatrixMTFProcessors
 */
class MatrixMTFProcessorFactory : public Tools::ProcessorFactory{
 public:
  MatrixMTFProcessorFactory(int matrix_width = 2);
  virtual ~MatrixMTFProcessorFactory();
  virtual shared_ptr<Processor> GenerateProcessor(int user_id);
 private:
   int matrix_width_;
};

} /* namespace Tools */

#endif /* MATRIXMTFPROCESSORFACTORY_H_ */
