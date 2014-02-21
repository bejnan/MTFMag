/*
 * TreeFactory_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "TreeFactory.h"
#include "TreeRoot.h"
#include "../Headers/Elements.h"
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

BOOST_AUTO_TEST_SUITE_END()
