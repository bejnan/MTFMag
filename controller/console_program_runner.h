#ifndef CONSOLEPROGRAMRUNNER_H_
#define CONSOLEPROGRAMRUNNER_H_

#include "program_runner.h"

namespace Base {

/**
 * TODO Now it is empty class
 * Aim of class is to read and prepare configuration
 * by console interaction with user. For more details
 * see base class.
 * @see ProgramRunner
 */
class ConsoleProgramRunner : public ProgramRunner {
 public:
  ConsoleProgramRunner();

  virtual ~ConsoleProgramRunner();

  virtual void SetProgram();

  virtual void RunProgram();

 protected:

  virtual void SetLearnTurns(int turn_amount);

  virtual void SetTestTurns(int turn_amount);

  virtual void SetResultOutputFrequency(int period);

  virtual void SetResultDetails(int value);

  virtual void SetAlgorithmsToTest(
        vector<string> algorithm_names) = 0;

};

} /* namespace Base */

#endif /* CONSOLEPROGRAMRUNNER_H_ */
