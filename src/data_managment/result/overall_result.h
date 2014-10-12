/*
 * overall_result.h
 *
 *  Created on: Jun 2, 2014
 *      Author: kuba
 */

#ifndef OVERALL_RESULT_H_
#define OVERALL_RESULT_H_

#include "result.h"

namespace Base {

/**
 * This class gathers results of all user for one algorithm.
 * There is no information about source of last notification, only
 * about moment in which happened (timestamp)
 */
struct OverallResult: public Result {

  OverallResult(string algorithm_name, int overal_penalty, int timestamp,
      string comment = "");

  virtual ~OverallResult();

  /**
   * In header line is no source id column
   * @return Header for all columns of results
   */
  virtual string HeaderLine();

  /**
   * Returns result similar to one in base class, but
   * there is no source id and overall penalty is sum
   * of penalties for all users counted by the same algorithm
   * @return Line of text with result and its description
   * @see Base::Result::ToString
   */
  virtual string ToString();

};

} /* namespace Base */

#endif /* OVERALL_RESULT_H_ */
