/*
 * LTree.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: kuba
 */

#include "LTree.h"

namespace Tree {

LTree::LTree(Node n, Element left_elem)
    : Node(left_elem), left_son_(n) {
}

LTree::~LTree() {
}

Node LTree::addSon(Node n)
{
  ;
}

} /* namespace Tools */
