#ifndef PROGRAM_RUNNER_H_
#define PROGRAM_RUNNER_H_

#include "../headers/elements.h"
#include "../headers/tools.h"

#include <vector>

using std::vector;

namespace Base {

/**
 * Interface for program to: <ul>
 * <li> Read configuration of program
 * <li> Prepare DataCollector and all other classes (instances of
 *      ProcessorFactory, Judge, DataOutput, etc.)
 * <li> Run program for given amount of turn (input lines)
 * </ul>
 * Child classes differ mainly in way of reading configuration
 * @see Base::DataCollector
 */
class ProgramRunner {
 public:
  virtual ~ProgramRunner() {
  }
  ;

  /**
   * Sets all classes needed to configure. Chooses algorithms,
   * judges, input and output.
   */
  virtual void SetProgram() = 0;

  /**
   * For given amount of turns (lines of input) DataCollector analyze input
   * with chosen earlier algorithms.
   */
  virtual void RunProgram() = 0;

 protected:

  /**
   * Sets number of turns (input lines) to process without judging results
   * @param turn_amount Amount of turns (input line) to process
   * @see Tools::Processor::Proceed
   */
  virtual void SetLearnTurns(int turn_amount) = 0;

  /**
   * Sets number of turns (input lines) to process with judging results
   * @param turn_amount Amount of turns (input line) to process
   * @see Tools::Processor::Proceed
   */
  virtual void SetTestTurns(int turn_amount) = 0;

  /**
   * Sets number of turns after which part result should be given to output
   * @param period Number of turns after which part result should be given to output
   */
  virtual void SetResultOutputFrequency(int period) = 0;

  /**
   * Method to set amount of details from Judge instance that will be printed
   * during program run
   * @param value Flag defining number of details from Judge
   */
  virtual void SetResultDetails(int value) = 0;  // TODO!

  /**
   * Sets list of pointers to ProcessorFactory instances to DataCollector
   * @param processor_factories ProcessorFactory instances that will be user in DataCollector during run
   */
  virtual void SetAlgorithmsToTest(
      vector<shared_ptr<Tools::ProcessorFactory> > processor_factories) = 0;
};

} /* namespace Base */

#endif /* PROGRAM_RUNNER_H_ */
