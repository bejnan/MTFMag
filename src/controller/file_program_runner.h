#ifndef FILE_PROGRAM_RUNNER_H_
#define FILE_PROGRAM_RUNNER_H_

#include "program_runner.h"

namespace Base {

/**
 * TODO Now it is empty class
 * Reads configuration of all elements from file given by path.
 * Sets all elements needed to run program and run it.
 * Configuration file is only interaction with user. After
 * reading file program should work independently.
 */
class FileProgramRunner : public ProgramRunner {
 public:
  FileProgramRunner(string file_path);
  virtual ~FileProgramRunner();

  virtual void SetProgram();

  virtual void RunProgram();

 protected:

  virtual void SetLearnTurns(int turn_amount);

  virtual void SetTestTurns(int turn_amount);

  virtual void SetResultFrequency(int period);

  virtual void SetResultDetails(int value);

  virtual void SetAlgorithmsToTest(
        vector<string> algorithm_names) = 0;

};

} /* namespace Base */

#endif /* FILE_PROGRAM_RUNNER_H_ */
