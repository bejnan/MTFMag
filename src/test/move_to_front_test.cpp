#define BOOST_TEST_DYN_LINK

#include "../headers/algorithms.h"

#include <boost/test/unit_test.hpp>

#include <memory>

using Algorithms::MoveToFront;
using std::shared_ptr;

BOOST_AUTO_TEST_SUITE(MoveToFront_Test)

//check correctness of adding elements to MoveToFront algorithm
BOOST_AUTO_TEST_CASE(AddingElement) {
  //initialization
  Algorithms::MoveToFront* mtf = new Algorithms::MoveToFront(
      Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> move_to_front_algorithm_ptr = shared_ptr<
      Algorithms::Algorithm>(mtf);
  for (int i = 1; i < 6; i++) {
    move_to_front_algorithm_ptr->AddElement(i);
  }
  //check element order
  for (int i = 1; i < 6; i++) {
    BOOST_CHECK_EQUAL(i, move_to_front_algorithm_ptr->GetContentPosition(i));
  }
}

//check correctness of notifying elements in MoveToFront algorithm
BOOST_AUTO_TEST_CASE(NotifyingElement) {
  //initialization
  Algorithms::MoveToFront* mtf = new Algorithms::MoveToFront(
      Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> move_to_front_algorithm_ptr = shared_ptr<
      Algorithms::Algorithm>(mtf);
  for (int i = 1; i < 6; i++) {
    move_to_front_algorithm_ptr->AddElement(i);
  }
  //check element order
  for (int i = 1; i < 6; i++) {
    BOOST_CHECK_EQUAL(i, move_to_front_algorithm_ptr->GetContentPosition(i));
  }
  move_to_front_algorithm_ptr->NotifyContent(5);
  BOOST_CHECK_EQUAL(1, move_to_front_algorithm_ptr->GetContentPosition(5));

  for (int i = 1; i < 5; i++) {
    BOOST_CHECK_EQUAL(i + 1,
                      move_to_front_algorithm_ptr->GetContentPosition(i));
  }

}

BOOST_AUTO_TEST_SUITE_END()

