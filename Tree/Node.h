/*
 * Node.h
 *
 *  Created on: Feb 11, 2014
 *      Author: kuba
 */

#ifndef NODE_H_
#define NODE_H_

#include "../Headers/Elements.h"

using namespace Base;

namespace Tree {

class Node {
 public:
  Node(Element& elem);
  virtual ~Node();
  virtual Node addSon(Node n);
  Element elem() {
    return elem_;
  }
 private:
  const Element elem_;
};

} /* namespace Tree */

#endif /* NODE_H_ */
