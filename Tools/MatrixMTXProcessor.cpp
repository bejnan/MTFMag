/*
 * MatrixMTXProcessor.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: kuba
 */

#include "MatrixMTXProcessor.h"

namespace Tools {

MatrixMTXProcessor::MatrixMTXProcessor(int user_id, string identifier,
                                       int width, bool random)
    : Processor(user_id, identifier),
      penalty_counter_(Tester(20, 20)),
      matrix_builder_(Matrix::MatrixBuilder::GetInstance()) {
  matrix_ = (
      (random) ?
          (matrix_builder_->WithMatrixWidth(width).WithRandomAdding()) :
          (matrix_builder_->WithMatrixWidth(width))).Generate();

}

MatrixMTXProcessor::~MatrixMTXProcessor() {
}

void MatrixMTXProcessor::Proceed(int id, bool lear) {
  if (!matrix_->HaveElement(id))
  {
  }
}

int MatrixMTXProcessor::GetPenalty() {
  return penalty_counter_.penalty();
}

} /* namespace Tools */
