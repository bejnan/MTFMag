#ifndef JUDGECOLLECTOR_H_
#define JUDGECOLLECTOR_H_

#include "../../headers/algorithms.h"
#include "../../headers/tools.h"
#include "../database.h"

#include <memory>
#include <vector>

using std::shared_ptr;

namespace Base {
/**
 * Collects details of tested algorithm's penalties.
 *
 */
class JudgeCollector {
 public:

  JudgeCollector(shared_ptr<Tools::Judge> judge_ptr);
  virtual ~JudgeCollector();

  virtual void AddAlgorithm(shared_ptr<Algorithms::Algorithm> new_algorithm);

  virtual void AnaliseNotification(int timsestamp, int sender_user_id,
                                   int receiver_user_id);

  virtual void AddProccessorFactory(shared_ptr<Tools::ProcessorFactory> procesor_factory_ptr);

  virtual vector<int> GetResult(int user_id);

  virtual vector<int> GetResultsSum();

  virtual vector<string> GetAlgorithmsNames();

 private:

  void AddProcessorsFromFactories(int user_id);

  vector<shared_ptr<Tools::ProcessorFactory> > processor_factories_;
  shared_ptr<Tools::Judge> judge_prototype_for_processors_;
  int start_timestamp;
  int last_timestamp;
  bool learn_mode;

};

} /* namespace Base */

#endif /* JUDGECOLLECTOR_H_ */
