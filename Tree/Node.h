/*
 * Node.h
 *
 *  Created on: Feb 11, 2014
 *      Author: kuba
 */

#ifndef NODE_H_
#define NODE_H_

#include "../Headers/Elements.h"
#include "../Headers/Tools.h"

using namespace Base;

namespace Tree {

/*
 * Base class for tree nodes.
 * It's a common part of every tree state implementation
 * Nodes are implemented to be part of full binary tree
 */
class Node {
 public:
  virtual ~Node();
  // Function to implement in delivery classes. In this class returning null class
  virtual shared_ptr<Node> AddSon(shared_ptr<Element> son_content) { return shared_ptr<Node>(); }
  // Function to implement in delivery classes. In this class returning null pointer
  virtual shared_ptr<Node> left_son() { return shared_ptr<Node>(); }
  // As above
  virtual shared_ptr<Node> right_son() { return shared_ptr<Node>(); }

  shared_ptr<Element> content() { return content_; }

  // Virtual for case of tree with sons
  virtual int children_count() { return 0; }

 protected:
  // content is node value
  Node(shared_ptr<Element> content);

 private:
  //Tree node content
  shared_ptr<Element> content_;
};

} /* namespace Tree */

#endif /* NODE_H_ */
