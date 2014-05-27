/*
 * JudgeCollector.cpp
 *
 *  Created on: May 23, 2014
 *      Author: kuba
 */

#include "judge_collector.h"

namespace Base {

JudgeCollector::JudgeCollector(shared_ptr<Tools::Judge> judge_ptr)
    : judge_prototype_for_processors_(judge_ptr),
      start_timestamp(0),
      last_timestamp(0),
      learn_mode(false) {

}

JudgeCollector::~JudgeCollector() {

}

void JudgeCollector::AddAlgorithm(
    shared_ptr<Algorithms::Algorithm> new_algorithm) {

}

void JudgeCollector::AnaliseNotification(int timestamp, int sender_user_id,
                                         int receiver_user_id) {
  if (!Database::GetInstance().Exists(sender_user_id)) {
    AddProcessorsFromFactories(sender_user_id);
  }
  vector<shared_ptr<Tools::Processor> >& processors = Database::GetInstance()
      .Query(sender_user_id);
  vector<shared_ptr<Tools::Processor> >::const_iterator processor_iterator;
  for (processor_iterator = processors.begin();
      processor_iterator != processors.end(); processor_iterator++) {
    (*processor_iterator)->Proceed(receiver_user_id, learn_mode);
  }

}

vector<int> JudgeCollector::GetResult(int user_id) {
  return vector<int>();
}

vector<int> JudgeCollector::GetResultsSum() {
  return vector<int>();
}

vector<string> JudgeCollector::GetAlgorithmsNames() {
  return vector<string>();
}

void JudgeCollector::AddProcessorsFromFactories(int user_id) {
  vector<shared_ptr<Tools::ProcessorFactory> >::iterator factory_iterator;
  shared_ptr<Tools::Processor> new_processor;
  for (factory_iterator = processor_factories_.begin();
      factory_iterator != processor_factories_.end(); factory_iterator++) {
    new_processor = (*factory_iterator)->GenerateProcessor(user_id);
    Database::GetInstance().AddToBase(new_processor);
  }
}

} /* namespace Base */
