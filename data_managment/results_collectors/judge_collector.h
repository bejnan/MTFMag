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

  /**
     * Method to add ProcessorFactory to generate new Processors
     * @see Tools::ProcessorFactory
     * @see Tools::Processor
     * @param procesor_factory_ptr Pointer to ProcessorFactory which will be
     * added to processor_factories_ vector
     */
    virtual void AddProccessorFactory(shared_ptr<Tools::ProcessorFactory> procesor_factory_ptr);


  /**
   * Method to get penalty for one user. Every position on vector represents penalty
   * counted for corresponding algorithm
   * @param user_id Choosen user
   * @return Vector of results for given algorithms
   */
  virtual vector<int> GetResult(int user_id);

  /**
   * Method to get penalty sum of every user for every algorithm. Every position on vector represents penalty
   * counted for corresponding algorithm.
   * @return Vector of sum results for given algorithms
   */
  virtual vector<int> GetResultsSum();

  /**
   * Method to get names of algorithms put by ProcessorFatories to processor_factories_ vector;
   * @return Algorithm names placed in DataCollector
   */
  virtual vector<string> GetAlgorithmsNames();

 private:

  /**
   * If sender of massage is new then DataCollector have to create new
   * Processors for this user using ProcessorFactories from
   * processor_factories_ vector;
   * @param user_id Id of user to create
   */
  void AddProcessorsFromFactories(int user_id);

  vector<shared_ptr<Tools::ProcessorFactory> > processor_factories_;
  shared_ptr<Tools::Judge> judge_prototype_for_processors_;
  int start_timestamp;
  int last_timestamp;
  bool learn_mode;

};

} /* namespace Base */

#endif /* JUDGECOLLECTOR_H_ */
