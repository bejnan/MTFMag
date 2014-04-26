/*
 * MatrixMTXProcessor.cpp
 *
 *  Created on: Mar 20, 2014
 *      Author: Jakub Banaszewski
 */

#include "matrix_mtf_processor.h"

namespace Tools {

MatrixMTFProcessor::MatrixMTFProcessor(
    int user_id, string identifier, int width,
    shared_ptr<Base::Element> element_prototype)
    : Processor(user_id, identifier),
      penalty_counter_(Tester(20, 20)) {
  shared_ptr<Algorithms::MatrixBuilder> matrix_builder =
      Algorithms::MatrixBuilder::GetInstance();
  matrix_ = matrix_builder->WithMatrixWidth(width).SetElementPrototype(
      element_prototype).Generate();
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
  return penalty_counter_.OveralPenalty();
}

void MatrixMTFProcessor::AddUser(int user_id) {
  matrix_->AddElement(user_id);
}

} /* namespace Tools */
