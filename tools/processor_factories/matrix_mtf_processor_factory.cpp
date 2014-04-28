/*
 * MatrixMTFProcessorFactory.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: Jakub Banaszewski
 */

#include "matrix_mtf_processor_factory.h"

namespace Tools {

MatrixMTFProcessorFactory::MatrixMTFProcessorFactory(int matrix_width)
    : matrix_width_(matrix_width) {
}

MatrixMTFProcessorFactory::~MatrixMTFProcessorFactory() {
}

shared_ptr<Processor> MatrixMTFProcessorFactory::GenerateProcessor(
    int user_id) {
  Judge* new_judge = new Tester(20, 20);
  shared_ptr<Judge> judge_ptr(new_judge);
  Algorithms::Algorithm* new_algorithm = new Algorithms::MTFMatrix(
      2, Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(new_algorithm);
  Processor* new_processor = new Processor(user_id, judge_ptr, algorithm_ptr);
  return shared_ptr<Processor>(new_processor);
}

} /* namespace Tools */
