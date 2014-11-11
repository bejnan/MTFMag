#pragma once

#include "../../data_managment/results.h"

#include <vector>
#include <memory>

using std::shared_ptr;
using std::pair;
using std::vector;

namespace Tools {

/**
 * Interface for algorithm judges.
 * Judge compares user choices (element notifications) with list of friends
 * prepared by algorithm. Further the chosen friend is on algorithm list
 * bigger penalty should be given.Implementations should deliver mechanism
 * to count penalty and get it overall value.
 * Details are not required but recommended.
 */

class Judge {
 public:

  /**
   * Empty destructor.
   */
  virtual ~Judge() { }

  /**
   * Main method for all Judge implementations. Count penalty using
   * position of element when notification happened (user chooses
   * friend to contact).
   * @param element_position Position of element given by used algorithm
   * in moment of user choice (notification)
   */
  virtual void CountPenalty(unsigned int element_position)  = 0;

  /**
   * Method to get overall penalty given by Judge.
   * @return Sum of all penalties
   */
  virtual unsigned long OveralPenalty() = 0;

  /**
   * Returns details of overall penalty.
   * Should remember every simple given penalty and time marker.
   * @return List of penalties with marker that allows to read linear order in
   * time between penalties. First element of pair represents penalty, second
   * represents time index.
   */
  virtual vector<pair<int, int> > PenaltyDetails() = 0;

  /**
   * Implementation of Prototype patter to clone instance of Judge
   * for ProcessorFactory.
   * @see ProcessorFactory
   */
  virtual shared_ptr<Judge> Clone() = 0;

};

} /* namespace tools */
