#ifndef PROGRAM_RUNNER_H_
#define PROGRAM_RUNNER_H_

#include "../headers/elements.h"
#include "../headers/tools.h"

#include <vector>

using std::vector;

namespace Base {

class ProgramRunner {
 public:
  virtual ~ProgramRunner() { };

  virtual void SetProgram() = 0;

  virtual void RunProgram() = 0;

 protected :

  virtual void SetLearnTurns(int turn_amount) = 0;

  virtual void SetTestTurns(int turn_amount) = 0;

  virtual void SetResultFrequency(int period) = 0;

  virtual void SetResultDetails(int value) = 0; // TODO!

  virtual void SetAlgorithmsToTest(vector<shared_ptr<Tools::ProcessorFactory > > processor_factories ) = 0;

};

} /* namespace Base */

#endif /* PROGRAM_RUNNER_H_ */
