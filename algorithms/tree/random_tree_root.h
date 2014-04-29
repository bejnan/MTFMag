#ifndef RANDOMTREEROOT_H_
#define RANDOMTREEROOT_H_

#include "tree_root.h"

#include <random>

using std::default_random_engine;
using std::uniform_real_distribution;
using std::to_string;

namespace Algorithms {
/**
 * Class very similar to TreeRoot.
 * Only difference is MoveElement method.
 * It uses random factor influenced by different
 * between elements to swap during moving element up.
 *
 * Base algorithm is the same. If there is notification
 * of element, algorithm tries to put it to top.
 * During way up there is competition with elements to swap.
 * If element looses, its parent tries to go up.
 */
class RandomTreeRoot : public TreeRoot {
 public:
  RandomTreeRoot(shared_ptr<Base::Element> node_core_prototype,
                 const double moving_up_propability = 0.75,
                 const double diff_influence = 0.5);
  virtual ~RandomTreeRoot();

  using TreeRoot::NotifyContent;
  using TreeRoot::GetContentPosition;
  using TreeRoot::AddElement;
  using TreeRoot::HaveElement;
  virtual string AlgorithmName();
 protected:
  /**
   * Different mechanism that equivalent in TreeRoot.
   * Every time element is about to move one level up
   * algorithm draws if it happens or movement stops.
   * Draw could be influence by difference between elements.
   * @param position Start position of notified element to move up
   *
   * @see RandomTreeRoot::DIFF_INFLUENCE
   * @see Element::Difference
   */
  virtual void MoveFromPositionToFront(int position);
  using TreeRoot::SwapElementsOnPositions;
  using TreeRoot::SortElementToList;
  using TreeRoot::CompareElementsOnPositions;
 private :
  /** Name identifier for algorithm */
  static const string ALGORITHM_NAME;

  /** Generator of random decisions*/
  default_random_engine generator_;

  /** Defines range of draw result*/
  uniform_real_distribution<double> distribution_;

  /** Counter of number of notifications */
  int notification_counter_;

  /** Probability of moving element one more level up */
  const double MOVING_UP_PROBABILITY;

  /** Influence on decision of moving element up by difference between
   * elements. If DIFF_INFLUENCE is large value element much bigger then
   * notified one could stop moving up process */
  const double DIFF_INFLUENCE;
};

} /* namespace Algorithms */

#endif /* RANDOMTREEROOT_H_ */
