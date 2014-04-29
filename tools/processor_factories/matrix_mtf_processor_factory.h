#ifndef MATRIXMTFPROCESSORFACTORY_H_
#define MATRIXMTFPROCESSORFACTORY_H_

#include "../processor_factory.h"
#include "../../headers/algorithms.h"
#include "../../headers/elements.h"
#include "../judges.h"

namespace Tools {

/**
 * Generates TreeProcessor using Tester judge and MTFMatrix algorithm.
 * @see Algorithms::MTFMatrix
 * @see Tools::Tester
 */
class MatrixMTFProcessorFactory : public Tools::ProcessorFactory{
 public:
  /**
   * Sets parameters to create MTFMatrix processor instance
   * @param matrix_width Width of matrix rows in MTFMatrix algorithm
   */
  MatrixMTFProcessorFactory(int matrix_width = 2);
  virtual ~MatrixMTFProcessorFactory();
  virtual shared_ptr<Processor> GenerateProcessor(int user_id);
 private:
  /** Width of matrix rows in MTFMatrix algorithm */
   int matrix_width_;
};

} /* namespace Tools */

#endif /* MATRIXMTFPROCESSORFACTORY_H_ */
