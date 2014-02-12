/*
 * Node.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: kuba
 */

#include "Node.h"

namespace Tree {

// Used by derived classes
Node::Node(shared_ptr<Element> content, int tree_position)
    : content_(content),
      tree_position_(tree_position) {

}
Node::~Node() {
}

} /* namespace Tree */
