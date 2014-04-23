/*
 * MatrixBuilder.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "matrix_builder.h"

namespace Algorithms {

MatrixBuilder::MatrixBuilder()
    : matrix_width_(1),
      element_prototype_(Base::Element::GetPrototype()) {
}

MatrixBuilder::~MatrixBuilder() {
}

shared_ptr<MatrixBuilder> MatrixBuilder::GetInstance() {
  return shared_ptr<MatrixBuilder>(new MatrixBuilder());
}

MatrixBuilder& MatrixBuilder::WithMatrixWidth(int width) {
  matrix_width_ = width;
  return *this;
}

MatrixBuilder& MatrixBuilder::SetElementPrototype(
    shared_ptr<Base::Element> element_prototype) {
  element_prototype_ = element_prototype;
  return *this;
}

MatrixBuilder& MatrixBuilder::ResetSetting() {
  matrix_width_ = 1;
  return *this;
}

shared_ptr<MTFMatrix> MatrixBuilder::Generate() {
  return shared_ptr<MTFMatrix>(new MTFMatrix(matrix_width_, element_prototype_));
}

} /* namespace Matrix */
