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
  Node(shared_ptr<Element> content, int tree_position=0);
  // position in tree
  int tree_position() {return tree_position_;}

 private:
  //Tree node content
  shared_ptr<Element> content_;
  // Place in tree hierarchy. Father have position div 2,
  // Sons have position *2 and *2+1.
  // Root have number 1.
  int tree_position_;
};

} /* namespace Tree */

#endif /* NODE_H_ */
