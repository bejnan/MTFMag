#ifndef MOVE_TO_FRONT_H_
#define MOVE_TO_FRONT_H_

#include "../algorithm.h"

#include <vector>
#include <memory>
#include <map>

using std::vector;
using std::shared_ptr;
using std::map;

namespace Algorithms {

class MoveToFront : public Algorithm {
 public:
  MoveToFront(shared_ptr<Base::Element> element_prototype);
  virtual ~MoveToFront();

  void NotifyContent(int user_id);

  void NotifyContent(int user_id, int notification_counter);

  int GetContentPosition(int user_id);

  void AddElement(int user_id);

  bool HaveElement(int user_id);

  string AlgorithmName();

 protected:
  void MoveFromPositionToFront(int position);

  void SwapElementsOnPositions(int position1, int position2);

  void SortElementToList();

  int CompareElementsOnPositions(int position1, int position2);

  double DifferenceBetweenElementsOnPosition(int position1, int position2);

 private:
  vector< shared_ptr<Base::Element> > algorithm_elements_;
  map<int, int> element_postion_;
  shared_ptr<Base::Element> element_prototype_;
  static const string ALGORITHM_NAME;
};

} /* namespace Base */

#endif /* MOVE_TO_FRONT_H_ */
