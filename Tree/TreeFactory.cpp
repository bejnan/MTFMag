/*
 * TreeFactory.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "TreeFactory.h"
#include <memory>

using std::shared_ptr;

namespace Tree {

TreeFactory<Element>::TreeFactory(TreeRoot& root) : root_(root) {
}


TreeFactory<Element>::~TreeFactory() {
}


void TreeFactory<Element>::AddElement(int id) {
  Element* elem = new Element(id);
  shared_ptr<Element> elem_ptr(elem);
  root_.tree_list_.push_back(elem_ptr);
}


void TreeFactory<Element>::DeleteElement(int id) {

}

} /* namespace Tree */
