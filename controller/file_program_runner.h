/*
 * file_program_runner.h
 *
 *  Created on: May 2, 2014
 *      Author: kuba
 */

#ifndef FILE_PROGRAM_RUNNER_H_
#define FILE_PROGRAM_RUNNER_H_

#include "program_runner.h"

namespace Base {

class FileProgramRunner : public ProgramRunner {
 public:
  FileProgramRunner();
  virtual ~FileProgramRunner();

  virtual void SetProgram();

  virtual void RunProgram();

 protected:

  virtual void SetLearnTurns(int turn_amount);

  virtual void SetTestTurns(int turn_amount);

  virtual void SetResultFrequency(int period);

  virtual void SetResultDetails(int value);

  virtual void SetAlgorithmsToTest(
      vector<shared_ptr<Tools::ProcessorFactory> > processor_factories);

};

} /* namespace Base */

#endif /* FILE_PROGRAM_RUNNER_H_ */
