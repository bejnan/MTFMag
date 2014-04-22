#ifndef MTFMATRIX_H_
#define MTFMATRIX_H_

#include "../headers/elements.h"

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


namespace Matrix {

/**
 * Aim of class is to organize elements in linear order.
 * Class implements algorithm similar to MTF (Move to front), but elements are
 * organized in rows with constant width and creates matrix. When element is
 * notified it is moved to first row moving by path
 * of smallest elements (using Element::Compare method) . For example
 * (let row size be 3) :
 *
 * Before notification (elements identifier) :
 * 1 2 3 (let elements be in order 1 < 2 < 3)
 * 4 5 6 (let elements be in order 4 < 5 < 6)
 * 7 8 9 (let elements be in order 7 < 8 < 9)
 *
 * After notification of 9 :
 * 9 2 3
 * 1 5 6
 * 8 9 4
 *
 * Another example (let order between elements be
 * the same as order between their id's) :
 * 1 3 2
 * 8 5 6
 * 9 4 7
 *
 * After notification of 4 :
 * 4 3 2
 * 8 1 6
 * 9 5 7
 *
 * To have linear order between elements they are sorted by
 * number of row and order in row. In short way, order is
 * by pair (#row_number,#element_compare_value) in alphabetic way.
 * For example (let order between elements be
 * the same as order between their id's) :
 * 1 3 2
 * 8 5 6
 * 9 4 7
 *
 * Gives order : 3 2 1 8 6 5 9 7 4
 *
 * Position of element in ordered way can be read by
 * MTFMatrix::GetContentPosiotion method
 *
 * @see Element::Compare to understand order between elements in row
 */
class MTFMatrix {

 public:
  /**
   * Sets row size of class matrix and
   * initialize all containers.
   * @param row_size size of row to store elements
   */
  MTFMatrix(int row_size);

  /**
   * Default destructor. Nothing to handle.
   */
  virtual ~MTFMatrix();

  /**
   * Check if element with given identifier is stored
   * in class instance
   * @param user_id Identifier of element
   * @return True if element with given identifier was added to class instance,
   * false otherwise
   */
  virtual bool HaveElement(int user_id);

  /**
   * Adds new element to matrix if no element with given id exists in class
   * instance.
   * @param element Pointer to new element.
   */
  virtual void AddElement(shared_ptr<Base::Element> element);

  /**
   * Main method of class. Notify element with given id.
   * After notification of element (Element::Notify method)
   * it moves element to front row as shown in class description.
   * @param user_id Identifier of element to notify
   */
  void NotifyContent(int user_id);

  /**
   * Gives current position of element in prepared algorithm order.
   * @param user_id Identifier of element
   * @return Position of element in linear order
   */
  int GetContentPosition(int user_id);

 protected:
  /**
   * Method to move element from given position to first row (happens
   * after notification). This method uses row_size_ property to move
   * element correctly.
   * @param position Position of element to move
   */
  void MoveFromPositionToFront(int position);

  /**
   * Method to switch pointers to elements stored in class.
   * Using this method guarantees fast access to elements
   * @param position1 Position of first element
   * @param position2 Position of second element
   */
  void SwitchElementsOnPositions(int position1, int position2);

  /**
   * Sorts elements in row to restore linear order.
   * Used after notification
   */
  void SortElementToList();

  /**
   * Compares elements by Element::Compare method
   * Element from position1 is "source" of method.
   * @param position1 Position of first element to compare.
   * @param position2 Position of second element to compare with.
   * @return Result of Element::Compare method
   * @see Element::Compare
   */
  int CompareElementsOnPositions(int position1, int position2);

  /**
   * Returns count of elements stored in class instance
   * @return Count of elements stored in class instance
   */
  unsigned int ElementCount();
 private:
  const int row_size_;     /**<  size of row in matrix  */
  vector<shared_ptr<Base::Element> > element_list_;
                           /**< List of elements row after row (all together) */
  vector<int> sorted_element_list_; /**< List of elements in linear order     */
  map<int, int> id_position_; /**< map to show position of node with given id */
};

} /* namespace Matrix */

#endif /* MTFMATRIX_H_ */
