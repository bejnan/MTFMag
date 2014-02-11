/*
 * LTree.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: kuba
 */

#include "LTree.h"

namespace Tree {

LTree::LTree(Leaf leaf, shared_ptr<Element> elem) : Node(leaf.content())
{
  Leaf* new_left_son = new Leaf(elem);
  left_son_ = shared_ptr<Element>(new_left_son);
}
LTree::~LTree() {}

shared_ptr<Node> LTree::AddSon(shared_ptr<Element> son_content)
{

}

} /* namespace Tools */
