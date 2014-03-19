/*
 * MTFMatrix_test.cpp
 *
 *  Created on: Mar 17, 2014
 *      Author: kuba
 */
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "MatrixBuilder.h"
#include "MTFMatrix.h"

BOOST_AUTO_TEST_SUITE(MTFMatrix)

BOOST_AUTO_TEST_CASE(MTFMatrixBuilder) {
  shared_ptr<Matrix::MatrixBuilder> builder =
      Matrix::MatrixBuilder::GetInstance();
  shared_ptr<Matrix::MTFMatrix> matrix =
      builder->WithMatrixWidth(2).Generate();

  shared_ptr<Base::Element> element;
  for (int i = 1; i < 6; i++) {
    element = shared_ptr<Base::Element>(new Base::Element(i));
    matrix->AddElement(element);
  }
  for (int i = 1; i < 6; i++) {
    BOOST_CHECK_EQUAL(i,matrix->GetContentPosition(i));
  }
}

BOOST_AUTO_TEST_CASE(MTFMatrixNotifiaction1) {
  shared_ptr<Matrix::MatrixBuilder> builder =
      Matrix::MatrixBuilder::GetInstance();
  shared_ptr<Matrix::MTFMatrix> matrix =
      builder->WithMatrixWidth(2).Generate();

  shared_ptr<Base::Element> element;
  for (int i = 1; i < 6; i++) {
    element = shared_ptr<Base::Element>(new Base::Element(i));
    matrix->AddElement(element);
  }

  matrix->NotifyContent(2);
  for (int i = 1; i < 6; i++) {
      BOOST_CHECK_EQUAL(i,matrix->GetContentPosition(i));
    }
  matrix->NotifyContent(5);
  BOOST_CHECK_EQUAL(1,matrix->GetContentPosition(5));
}



BOOST_AUTO_TEST_SUITE_END()
