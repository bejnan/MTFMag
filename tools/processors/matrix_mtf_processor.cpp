/*
 * MatrixMTXProcessor.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: Jakub Banaszewski
 */

#include "matrix_mtf_processor.h"

namespace Tools {

MatrixMTFProcessor::MatrixMTFProcessor(int user_id, string identifier,
                                       int width)
    : Processor(user_id, identifier),
      penalty_counter_(Tester(20, 20)),
      matrix_builder_(Matrix::MatrixBuilder::GetInstance()),
      user_container_prototype(Base::SimpleElement::GetPrototype()) {
  matrix_ = (matrix_builder_->WithMatrixWidth(width)).Generate();
}

MatrixMTFProcessor::~MatrixMTFProcessor() {
}

void MatrixMTFProcessor::Proceed(int user_id, bool learn) {
  if (!matrix_->HaveElement(user_id)) {
    AddUser(user_id);
  }
  if (!learn) {
    int position = matrix_->GetContentPosition(user_id);
    penalty_counter_.CountPenalty(position);
  }
  matrix_->NotifyContent(user_id);
}

int MatrixMTFProcessor::GetPenalty() {
  return penalty_counter_.penalty();
}

void MatrixMTFProcessor::AddUser(int user_id) {
  matrix_->AddElement(user_container_prototype->Clone(user_id));
}

} /* namespace Tools */
