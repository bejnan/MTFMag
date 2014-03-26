/*
 * MatrixMTFProcessorFactory.cpp
 *
 *  Created on: Mar 22, 2014
 *      Author: kuba
 */

#include "matrix_mtf_processor_factory.h"

namespace Tools {

MatrixMTFProcessorFactory::MatrixMTFProcessorFactory(int matrix_width)
    : algorithm_name_(to_string(matrix_width) + "-MTF_Matrix"),
      matrix_width_(matrix_width) {
}

MatrixMTFProcessorFactory::~MatrixMTFProcessorFactory() {
}

shared_ptr<Processor> MatrixMTFProcessorFactory::GenerateProcessor(
    int user_id) {
  MatrixMTFProcessor* new_processor = new MatrixMTFProcessor(user_id,
                                                             algorithm_name_,
                                                             matrix_width_);
  return shared_ptr<Processor>(new_processor);
}

} /* namespace Tools */
