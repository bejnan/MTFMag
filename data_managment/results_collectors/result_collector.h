/*
 * result_collector.h
 *
 *  Created on: May 28, 2014
 *      Author: kuba
 */

#ifndef RESULT_COLLECTOR_H_
#define RESULT_COLLECTOR_H_

#include "data_collector.h"
#include "../database.h"
#include "judge_collector.h"

namespace Base {

class ResultCollector {
 public:
  ResultCollector();
  virtual ~ResultCollector();

  /**
   * Method to run Processors. Every turn means one line of input is read
   * and proceed by Processors.
   * @param turn_amount   Number of input line to proceed
   * @param learn         If true then no penalty is added.
   */
  virtual void RunTurns(int turn_amount, bool learn = false);

 private :
  /**
    * Method used by RunTurns to run Processors from Database
    * @param user_id       Id of contact which sends message
    * @param receiver_id   Id of receiver of message
    * @param learn         If learn is true no penalty is counted
    * @see Tools::Processor
    * @see Database
    */
   void RunProcessor(int user_id, int receiver_id, bool learn = false);

   /**
    * If sender of massage is new then DataCollector have to create new
    * Processors for this user using ProcessorFactories from
    * processor_factories_ vector;
    * @param user_id Id of user to create
    */
   void AddProcessorsFromFactories(int user_id);

   DataCollector
};

} /* namespace Base */

#endif /* RESULT_COLLECTOR_H_ */
