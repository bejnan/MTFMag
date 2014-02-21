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

BOOST_AUTO_TEST_SUITE_END()
