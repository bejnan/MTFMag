/*
 * result_collector.h
 *
 *  Created on: May 28, 2014
 *      Author: kuba
 */

#ifndef RESULT_COLLECTOR_H_
#define RESULT_COLLECTOR_H_

#include "data_collector.h"
#include "judge_collector.h"

#include "../database.h"

#include <memory>

using std::shared_ptr;

namespace Base {

class ResultCollector {
 public:
  ResultCollector(shared_ptr<DataCollector> data_collector, shared_ptr<JudgeCollector> judge_collector);
  virtual ~ResultCollector();

  void SetTurns(int learn_turns, int test_turns);

  void SetResultFrequency(int turn_count);

  //void SetResultsDetails();

  virtual void Run();

 private :
   shared_ptr<DataCollector> data_collector_;
   shared_ptr<JudgeCollector> judge_collector_;

   int learn_turns_;
   int test_turns_;
   int turns_between_results_;

   bool was_already_run_;
};

} /* namespace Base */

#endif /* RESULT_COLLECTOR_H_ */
