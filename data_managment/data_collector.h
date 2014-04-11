#ifndef DATACOLLECTOR_H_
#define DATACOLLECTOR_H_

#include "data_provider.h"
#include "database.h"
#include "data_output.h"
#include "../headers/tools.h"

#include <sstream>
#include <algorithm>
#include <memory>
#include <vector>

using std::accumulate;
using std::stringstream;
using std::vector;
using std::shared_ptr;
using std::pair;
using std::make_pair;

namespace Base {
/**
 * Class to connect all parts of algorithms.
 *\dot
 * digraph G {
 * DataCollector -> Database;
 * DataCollector -> DataProvider;
 * DataCollector -> DataOutput;
 * DataCollector -> ProcessorFactory;
 *
 * Database         -> Processor;
 * ProcessorFactory -> Processor;
 *
 * DataProvider -> FileDataProvider;
 * DataOutput   -> CsvDataOutput;
 * DataOutput   -> CsvFileDataOutput;
 *
 * Processor -> Tester;
 * Processor -> Algorithms;
 * }
 *\enddot
 * It provides data to Processors and print penalties.
 * It also generates Processors for every user, object, contact (id) that comes
 * from DataProvider.
 *\dot
 * digraph H {
 * DataProvider      -> DataCollector [label = " New user_id"] ;
 * DataCollector     -> ProcessorFactory [label = " New user_id"];
 * ProcessorFactory  -> Database [label = " New Processor with given user_id"];
 * }
 *\enddot
 * ProcessorFactiories are needed to generate Processors for
 * every user (user_id) that comes from DataProvider.
 * Every ProcessorFactiory represents one algorithm.
 *
 */
class DataCollector {
 public:
  /**
   * Constructor responsible for initialization all connected objects except
   * objects given as parameters
   * @param data_input  Data input to proceed
   * @param data_output Output for results
   */
  DataCollector(DataProvider& data_input, shared_ptr<DataOutput> data_output);

  /**
   * Default destructor. No object need to be deleted or handled in special way.
   */
  virtual ~DataCollector();

  /**
   * Method to add ProcessorFactory to generate new Processors
   * @see ProcessorFactory
   * @see Processor
   * @param procesor_factory_ptr Pointer to ProcessorFactory which will be
   * added to processor_factories_ vector
   */
  virtual void AddProccessorFactory(shared_ptr<Tools::ProcessorFactory> procesor_factory_ptr);

  /**
   * Method to run Processors. Every turn means one line of input is read
   * and proceed by Processors.
   * @param turn_amount   Number of input line to proceed
   * @param learn         If true then no penalty is added.
   */
  virtual void RunTurns(int turn_amount, bool learn = false);

  /**
   * Method prints one line of results using DataOutput instance
   * @see DataOutput
   */
  virtual void PrintActualResults();

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
  // Run processor with given id and signal to receiver_id
  void RunProcessor(int id, int receiver_id, bool learn = false);
  void AddProcessorsFromFactories(int id);

  DataProvider& data_input_;
  shared_ptr<DataOutput> data_output_;
  Database processors_base_;
  vector<shared_ptr<Tools::ProcessorFactory> > processor_factories_;
  int turns_already_proceed;
};

} /* namespace Tree */

#endif /* DATACOLLECTOR_H_ */
