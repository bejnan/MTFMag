#ifndef MOVE_TO_FRONT_H_
#define MOVE_TO_FRONT_H_

#include "../algorithm.h"
#include "../../headers/exceptions.h"

#include <vector>
#include <memory>
#include <map>

using std::vector;
using std::shared_ptr;
using std::map;

namespace Algorithms {

/**
 * Implementation of basic Move To Front algorithm.
 * Every time notification happens element is moved
 * from its position to first one moving all higher elements
 * on list one position down.
 */
class MoveToFront : public Algorithm {
 public:
  MoveToFront(shared_ptr<Base::Element> element_prototype);
  virtual ~MoveToFront();

  void NotifyContent(int user_id);

  void NotifyContent(int user_id, int notification_counter);

  int GetContentPosition(int user_id);

  void AddElement(int user_id);

  bool HaveElement(int user_id);

  /**
   * Return name of algorithm to identify method.
   * @return Name of method used as algorithm
   */
  static string AlgorithmName();

  shared_ptr<Algorithm> Clone();

 protected:
  /**
   * Moves element from it's position to first one moving
   * higher elements one position down
   * @param position Position of element to move
   */
  void MoveFromPositionToFront(int position);

  void SwapElementsOnPositions(int position1, int position2);

  /**
   * Empty method. Not needed in this algorithm. List of algorithm elements
   * is always already sorted.
   */
  void SortElementToList();

  int CompareElementsOnPositions(int position1, int position2);

  double DifferenceBetweenElementsOnPosition(int position1, int position2);

 private:
  /** List of all elements. It's also order of elements generated by algorithm.  */
  vector<shared_ptr<Base::Element> > algorithm_elements_;

  /** Map to locate element's position by it's id */
  map<int, int> element_position_;

  /** Generator of new elements (new added to algorithm) */
  shared_ptr<Base::Element> element_prototype_;

  /** Name of algorithm*/
  static const string ALGORITHM_NAME;
};

} /* namespace Base */

#endif /* MOVE_TO_FRONT_H_ */