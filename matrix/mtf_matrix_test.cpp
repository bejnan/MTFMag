/*
 * MTFMatrix_test.cpp
 *
 *  Created on: Mar 17, 2014
 *      Author: Jakub Banaszewski
 */
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "matrix_builder.h"
#include "mtf_matrix.h"

BOOST_AUTO_TEST_SUITE(MTFMatrix)

//check correctness of adding elements to MTFMatrix
BOOST_AUTO_TEST_CASE(AddingElement) {
  //initialization
  shared_ptr<Matrix::MatrixBuilder> builder =
      Matrix::MatrixBuilder::GetInstance();
  shared_ptr<Matrix::MTFMatrix> matrix = builder->WithMatrixWidth(2).Generate();
  shared_ptr<Base::Element> element;
  for (int i = 1; i < 6; i++) {
    element = shared_ptr<Base::Element>(new Base::Element(i));
    matrix->AddElement(element);
  }

  //check element order
  for (int i = 1; i < 6; i++) {
    BOOST_CHECK_EQUAL(i, matrix->GetContentPosition(i));
  }
}

//check correctness of adding elements to MTFMatrix with simple notification
BOOST_AUTO_TEST_CASE(MTFMatrixNotifiaction) {
  //initialization
  shared_ptr<Matrix::MatrixBuilder> builder =
      Matrix::MatrixBuilder::GetInstance();
  shared_ptr<Matrix::MTFMatrix> matrix = builder->WithMatrixWidth(2).Generate();

  shared_ptr<Base::Element> element;
  for (int i = 1; i < 6; i++) {
    element = shared_ptr<Base::Element>(new Base::Element(i));
    matrix->AddElement(element);
  }

  // Element with id = 2 is in first row, so it doesn't change position
  matrix->NotifyContent(2);
  for (int i = 1; i < 6; i++) {
    BOOST_CHECK_EQUAL(i, matrix->GetContentPosition(i));
  }
}

BOOST_AUTO_TEST_CASE(MTFMatrixTwoNotifiactions) {
  //initialization
  shared_ptr<Matrix::MatrixBuilder> builder =
      Matrix::MatrixBuilder::GetInstance();
  shared_ptr<Matrix::MTFMatrix> matrix = builder->WithMatrixWidth(2).Generate();

  shared_ptr<Base::Element> element;
  for (int i = 1; i < 6; i++) {
    element = shared_ptr<Base::Element>(new Base::Element(i));
    matrix->AddElement(element);
  }

  //as above, no position change
  matrix->NotifyContent(2);
  for (int i = 1; i < 6; i++) {
    BOOST_CHECK_EQUAL(i, matrix->GetContentPosition(i));
  }

  // last element become first
  matrix->NotifyContent(5);
  BOOST_CHECK_EQUAL(1, matrix->GetContentPosition(5));
}

BOOST_AUTO_TEST_SUITE_END()
