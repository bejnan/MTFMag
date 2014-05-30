#ifndef MTFMATRIX_H_
#define MTFMATRIX_H_

#include "../../headers/elements.h"
#include "../../headers/exceptions.h"
#include "../algorithm.h"

#include <vector>
#include <map>
#include <memory>
#include <algorithm>

using std::vector;
using std::map;
using std::shared_ptr;
using std::sort;
using std::min;
using std::max;

namespace Algorithms {

/**
 * Aim of class is to organize elements in linear order.
 * Class implements algorithm similar to MTF (Move to front), but elements are
 * organized in rows with constant width and creates matrix. When element is
 * notified it is moved to first row moving by path
 * of smallest elements (using Element::Compare method) . For example
 * (let row size be 3) :
 *
 * Before notification (elements identifier) : <br>
 * 1 2 3 (let elements be in order 1 < 2 < 3) <br>
 * 4 5 6 (let elements be in order 4 < 5 < 6) <br>
 * 7 8 9 (let elements be in order 7 < 8 < 9) <br>
 *
 * After notification of 9 : <br>
 * 9 2 3 <br>
 * 1 5 6 <br>
 * 8 9 4 <br>
 *
 * Another example (let order between elements be
 * the same as order between their id's) : <br>
 * 1 3 2 <br>
 * 8 5 6 <br>
 * 9 4 7 <br>
 *
 * After notification of 4 : <br>
 * 4 3 2 <br>
 * 8 1 6 <br>
 * 9 5 7 <br>
 *
 * To have linear order between elements they are sorted by
 * number of row and order in row. In short way, order is
 * by pair (row number, element compare value) in alphabetic way.
 * For example (let order between elements be
 * the same as order between their id's) : <br>
 * 1 3 2 <br>
 * 8 5 6 <br>
 * 9 4 7 <br>
 *
 * Gives order : 3 2 1 8 6 5 9 7 4
 *
 * Position of element in ordered way can be read by
 * MTFMatrix::GetContentPosiotion method
 *
 * @see Base::Element::Compare to understand order between elements in row
 */
class MTFMatrix : public Algorithm {

 public:
  /**
   * Sets row size of class matrix, prototype to create Element instances and
   * initialize all containers.
   * @param row_size size of row to store elements
   * @param element_prototype Prototype to generate new elements
   */
  MTFMatrix(shared_ptr<Base::Element> element_prototype, int row_size = 2);

  /**
   * Default destructor. Nothing to handle.
   */
  virtual ~MTFMatrix();

  virtual bool HaveElement(int user_id);

  virtual void AddElement(int user_id);

  void NotifyContent(int user_id);

  void NotifyContent(int user_id, int notification_count);

  int GetContentPosition(int user_id);

  /**
   * Return name of algorithm to identify method.
   * @return Name of method used as algorithm
   */
  static string AlgorithmName();

  string GetAlgorithmName();

  virtual shared_ptr<Algorithm> Clone();

 protected:
  /**
   * Method to move element from given position to first row (happens
   * after notification). This method uses row_size_ property to move
   * element correctly.
   * @param position Position of element to move
   */
  void MoveFromPositionToFront(int position);

  /**
   * Guarantees switch control and fast access to elements after switch.
   * @param position1 Position of first element
   * @param position2 Position of second element
   */
  void SwapElementsOnPositions(int position1, int position2);

  void SortElementToList();

  int CompareElementsOnPositions(int position1, int position2);

  double DifferenceBetweenElementsOnPosition(int position1, int position2);

  /**
   * Returns count of elements stored in class instance
   * @return Count of elements stored in class instance
   */
  unsigned int ElementCount();

 private:

  /**  size of row in matrix  */
  const int row_size_;

  /** List of elements row after row (all together) */
  vector<shared_ptr<Base::Element> > element_list_;

  /** List of elements in linear order */
  vector<int> sorted_element_list_;

  /** map to show position of node with given id */
  map<int, int> id_position_;

  shared_ptr<Base::Element> element_prototype_;

  /** Name identifier for algorithm */
  static const string ALGORITHM_NAME;
};

} /* namespace Algorithms */

#endif /* MTFMATRIX_H_ */
