#ifndef TREEROOT_H_
#define TREEROOT_H_

#include "../../headers/elements.h"
#include "../algorithm.h"
#include <vector>
#include <map>
#include <memory>

using std::vector;
using std::map;
using std::shared_ptr;

namespace Algorithms {

/**
 * This algorithm similar as Move To Front moves chosen element
 * to first position. Difference is in a way it happens.
 * All elements are stored in full binary tree and every notification moves
 * element up to root node replacing other nodes in it's path.
 * For example, lets tree look like : <pre>
 *     1
 *   2   3
 *  4 5 6 7
 * </pre>
 * Linear order of elements is : <br>
 * 1 3 2 7 6 5 4 <br>
 *
 * After notify element with identifier 5 tree will look : <pre>
 *     5
 *   1   3
 *  4 2 6 7
 * </pre>
 *
 * After moving element to front linear order is : <br>
 * 5 3 1 7 6 4 2 <br>
 */
class TreeRoot : public Algorithm {

 public:
  TreeRoot(shared_ptr<Base::Element> node_core_prototype);
  virtual ~TreeRoot();

  virtual void NotifyContent(int user_id);

  virtual void NotifyContent(int user_id, int notification_counter);

  virtual int GetContentPosition(int user_id);

  virtual void AddElement(int user_id);

  virtual bool HaveElement(int user_id) = 0;

 protected:
  /**
   * Moves element to root of the tree in the was shown
   * in class description.
   * @param position Start position of element in tree
   * structure
   */
  virtual void MoveFromPositionToFront(int position);

  virtual void SwapElementsOnPositions(int position1, int position2);

  void SortElementToList();

  int CompareElementsOnPositions(int position1, int position2);
 private:
  /** Tree implemented by array (parent is on child's position div 2) */
  vector<shared_ptr<Base::Element> > tree_list_;

  /** List of elements in order (level priority, then value) */
  vector<int> sorted_content_list_;

  /** Map of elements to get position of element in tree. Identifier
   * is key, value represent position in tree_list_;         */
  map<int, int> id_position_;

  /** Prototype for elements used in AddElement method
   * @see TreeRoot::AddElement                               */
  shared_ptr<Base::Element> element_prototype_;
};

} /* namespace Algorithms */

#endif /* TREEROOT_H_ */
