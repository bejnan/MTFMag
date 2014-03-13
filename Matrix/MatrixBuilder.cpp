/*
 * MatrixBuilder.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: kuba
 */

#include "MatrixBuilder.h"

namespace Matrix {

MatrixBuilder::MatrixBuilder()
    : matrix_width_(1),
      with_random_(false) {
}

MatrixBuilder::~MatrixBuilder() {
}

shared_ptr<MatrixBuilder> MatrixBuilder::GetInstance() {
  return shared_ptr<MatrixBuilder>(new MatrixBuilder());
}

shared_ptr<MatrixBuilder> MatrixBuilder::WithMatrixWidth(int width) {
  matrix_width_ = width;
  return shared_ptr<MatrixBuilder>(this);
}
shared_ptr<MatrixBuilder> MatrixBuilder::WithRandomAdding() {
  with_random_ = true;
  return shared_ptr<MatrixBuilder>(this);
}
shared_ptr<MatrixBuilder> MatrixBuilder::ResetSetting() {
  matrix_width_ = 1;
  with_random_ = false;
  return shared_ptr<MatrixBuilder>(this);
}

shared_ptr<MTFMatrix> MatrixBuilder::Generate() {
  return shared_ptr<MTFMatrix>(new MTFMatrix());
}

} /* namespace Matrix */
