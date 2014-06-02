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

class OverallResult : public Result {
 public:

  OverallResult(string algorithm_name, int overal_penalty,
                int timestamp, string comment = "");

  virtual ~OverallResult();

  virtual string HeaderLine();

  virtual string ToString();

};

} /* namespace Base */

#endif /* OVERALL_RESULT_H_ */
