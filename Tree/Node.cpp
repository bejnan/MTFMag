/*
 * Node.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: kuba
 */

#include "Node.h"

namespace Tree {

// Used by derived classes
Node::Node(shared_ptr<Element> content)
    : content_(content) {

}
Node::~Node() {
}

} /* namespace Tree */
