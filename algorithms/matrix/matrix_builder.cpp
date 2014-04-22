/*
 * MatrixBuilder.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "matrix_builder.h"

namespace Matrix {

MatrixBuilder::MatrixBuilder()
    : matrix_width_(1) {
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

MatrixBuilder& MatrixBuilder::ResetSetting() {
  matrix_width_ = 1;
  return *this;
}

shared_ptr<MTFMatrix> MatrixBuilder::Generate() {
  return shared_ptr<MTFMatrix>(new MTFMatrix(matrix_width_));
}

} /* namespace Matrix */
