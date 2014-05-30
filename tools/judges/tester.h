#ifndef TESTER_H_
#define TESTER_H_

#include "judge.h"

using std::make_pair;

namespace Tools {
/**
 * Counter of penalties. This class assume that user used
 * screen with scroll and searching. If notified friend (element)
 * is on first page user can find it in no time. If element is on
 * second page user have to scroll to find it. If element is further
 * user uses search which finds element in constant time (MAX_PENALTY), but bigger than
 * searching on first two screens (because user have to do it anyway to know,
 * that element isn't there).
 */
class Tester : public Judge {
 public:
  /**
   * Initialize penalty parameters
   * @param first_page_list_size Size of first page. Notification of elements that are located there
   * costs nothing in this model.
   * @param second_page_list_size Size of second page.Notification of elements that are located there
   * costs (position - first_page_size).
   */
  Tester(int first_page_list_size, int second_page_list_size);

  /**
   * Default destructor. Nothing to handle
   */
  virtual ~Tester();

  /**
   * Checks position of notified element and compare it
   * with set parameters. After that adds adequate penalty to penalty_sum_ property.
   * @param element_position Position on which element was found before notification.
   */
  virtual void CountPenalty(unsigned int element_position);

  /**
   * Getter of overall penalty
   * @return Sum of all counted penalties
   */
  virtual int OveralPenalty() {
    return penalty_sum_;
  }

  /**
   * Returns all given penalties on FIFO order.
   * @return List with pairs of penalties and counter of CountPenalties calls.
   */
  virtual vector<pair<int, int> > PenaltyDetails();

  virtual shared_ptr<Judge> Clone();

 private:
  unsigned int first_page_list_size_; /**< Size of first page
   (with no penalty)      */

  unsigned int second_page_list_size_; /**< Size of second page
   (with counted penalty) */

  unsigned const int MAX_PENALTY; /**< Penalty for elements founded
   further than on first two pages */

  int turn_counter; /**< Count numbers of CountPenalty calls   */

  unsigned long penalty_sum_;        /**< Sum of all penalties */

  vector<pair <int, int> > penalties_; /**< List of all penaties */
};

} /* namespace Tree */

#endif /* TESTER_H_ */
