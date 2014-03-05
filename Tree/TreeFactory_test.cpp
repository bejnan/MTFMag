/*
 * TreeFactory_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "TreeFactory.h"
#include "TreeRoot.h"
#include "RandomTreeRoot.h"
#include "../Headers/Elements.h"

#include <vector>
#include <algorithm>
#include <random>

using std::default_random_engine;
using std::uniform_int_distribution;
using std::find;
using std::vector;

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TreeFactory)

BOOST_AUTO_TEST_CASE(AddingTest) {

  Tree::TreeRoot root;
  Tree::TreeFactory tree_factory(root);

  tree_factory.AddElement<Base::Element>(1);
  tree_factory.AddElement<Base::Element>(2);
  tree_factory.AddElement<Base::Element>(3);
}

BOOST_AUTO_TEST_CASE(RootTest) {

  Tree::TreeRoot root;
  Tree::TreeFactory tree_factory(root);

  tree_factory.AddElement<Base::SimpleElement>(1);
  tree_factory.AddElement<Base::SimpleElement>(2);
  tree_factory.AddElement<Base::SimpleElement>(3);

  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 1);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 3);

  root.NotifyContent(3);
  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 3);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 1);
}

BOOST_AUTO_TEST_CASE(NotifyTest) {

  Tree::TreeRoot root;
  Tree::TreeFactory tree_factory(root);

  tree_factory.AddElement<Base::SimpleElement>(1);
  tree_factory.AddElement<Base::SimpleElement>(2);
  tree_factory.AddElement<Base::SimpleElement>(3);

  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 1);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 3);

  root.NotifyContent(3);
  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 3);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 1);

  tree_factory.AddElement<Base::SimpleElement>(4);
  root.NotifyContent(4);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 2);
  BOOST_CHECK_EQUAL(root.GetContentPosition(4), 1);
  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 3);

}

BOOST_AUTO_TEST_CASE(RandomTreeTest) {
  Tree::RandomTreeRoot r_root;
  Tree::TreeFactory tree_factory(r_root);

  for (int i = 1; i < 10; i++)
    tree_factory.AddElement<Base::SimpleElement>(i);

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

BOOST_AUTO_TEST_CASE(TreeTest) {
  const int TEST_LIMIT = 20;
  Tree::TreeRoot root;
  Tree::TreeFactory tree_factory(root);
  default_random_engine generator;
  uniform_int_distribution<int> distribution(1, TEST_LIMIT);
  for (int i = 1; i < TEST_LIMIT; i++)
    tree_factory.AddElement<Base::SimpleElement>(i);

  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 1);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 3);

  for (int i = 0; i < TEST_LIMIT*TEST_LIMIT; i++) {
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
BOOST_AUTO_TEST_CASE(RandomTreeTest2) {
  const int TEST_LIMIT = 20;
  Tree::RandomTreeRoot root;
  Tree::TreeFactory tree_factory(root);
  default_random_engine generator;
  uniform_int_distribution<int> distribution(1, TEST_LIMIT);
  for (int i = 1; i < TEST_LIMIT; i++)
    tree_factory.AddElement<Base::SimpleElement>(i);

  BOOST_CHECK_EQUAL(root.GetContentPosition(1), 1);
  BOOST_CHECK_EQUAL(root.GetContentPosition(3), 3);

  for (int i = 0; i < TEST_LIMIT*TEST_LIMIT; i++) {
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
