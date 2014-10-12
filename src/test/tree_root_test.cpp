/*
 * TreeFactory_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "../headers/elements.h"
#include "../headers/algorithms.h"

#include <vector>
#include <algorithm>
#include <random>
#include <exception>

using std::default_random_engine;
using std::uniform_int_distribution;
using std::find;
using std::vector;

using namespace Algorithms;

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TreeFactory)

BOOST_AUTO_TEST_CASE(AddingTest) {

  TreeRoot root(Base::SimpleElement::GetPrototype());

  root.AddElement(1);
  root.AddElement(2);
  root.AddElement(3);
}

BOOST_AUTO_TEST_CASE(NotifySimpleRotationTest) {

  TreeRoot root(Base::SimpleElement::GetPrototype());

  root.AddElement(1);
  root.AddElement(2);
  root.AddElement(3);

  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 1);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 3);

  root.NotifyContent(3);
  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 3);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 1);
}

BOOST_AUTO_TEST_CASE(NotifyDoubleRotationTest) {

  TreeRoot root(Base::SimpleElement::GetPrototype());

  root.AddElement(1);
  root.AddElement(2);
  root.AddElement(3);

  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 1);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 3);

  root.NotifyContent(3);
  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 3);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 1);

  root.AddElement(4);
  root.NotifyContent(4);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 2);
  BOOST_CHECK_EQUAL(root.GetContentPosition(4), 1);
  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 3);

}

//Test checks if RandomTreeRoot doent's lose elements
BOOST_AUTO_TEST_CASE(RandomTreeAddAndNotificationTest) {
  RandomTreeRoot r_root(Base::SimpleElement::GetPrototype());

  for (int i = 1; i < 10; i++)
    r_root.AddElement(i);

  BOOST_CHECK_EQUAL(r_root.GetContentPosition(1), 1);
  BOOST_CHECK_EQUAL(r_root.GetContentPosition(3), 3);

  r_root.NotifyContent(1);
  r_root.NotifyContent(4);
  r_root.NotifyContent(7);
  r_root.NotifyContent(9);

  vector<int> positions;

  for (int i = 1; i < 10; i++) {
    positions.push_back(r_root.GetContentPosition(i));
  }
  for (int i = 1; i < 10; i++) {
    BOOST_CHECK_EQUAL(
        true, find(positions.begin(), positions.end(), i) != positions.end());
  }

}

//Test checks if TreeRoot doent's lose elements on longer distance
BOOST_AUTO_TEST_CASE(TreeCompleteTest) {
  const int TEST_LIMIT = 20;

  TreeRoot root(Base::SimpleElement::GetPrototype());
  default_random_engine generator;
  uniform_int_distribution<int> distribution(1, TEST_LIMIT - 1);

  for (int i = 1; i < TEST_LIMIT; i++)
    root.AddElement(i);

  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 1);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 3);

  for (int i = 0; i < TEST_LIMIT * TEST_LIMIT; i++) {
    root.NotifyContent(distribution(generator));
  }

  vector<int> positions;

  for (int i = 1; i < TEST_LIMIT; i++) {
    positions.push_back(root.GetContentPosition(i));
  }
  for (int i = 1; i < TEST_LIMIT; i++) {
    BOOST_CHECK_EQUAL(
        true, find(positions.begin(), positions.end(), i) != positions.end());
  }

}

//Test checks if RandomTreeRoot doesn't lose elements on longer distance
BOOST_AUTO_TEST_CASE(RandomTreeComplete) {
  const int TEST_LIMIT = 20;

  RandomTreeRoot root(Base::SimpleElement::GetPrototype());
  default_random_engine generator;
  uniform_int_distribution<int> distribution(1, TEST_LIMIT - 1);

  for (int i = 1; i < TEST_LIMIT; i++)
    root.AddElement(i);

  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 1);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 3);

  for (int i = 0; i < TEST_LIMIT * TEST_LIMIT; i++) {
    root.NotifyContent(distribution(generator));
  }
  vector<int> positions;

  for (int i = 1; i < TEST_LIMIT; i++) {
    positions.push_back(root.GetContentPosition(i));
  }
  for (int i = 1; i < TEST_LIMIT; i++) {
    BOOST_CHECK_EQUAL(
        true, find(positions.begin(), positions.end(), i) != positions.end());
  }

}

BOOST_AUTO_TEST_SUITE_END()
