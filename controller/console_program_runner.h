/*
 * ConsoleProgramRunner.h
 *
 *  Created on: May 2, 2014
 *      Author: kuba
 */

#ifndef CONSOLEPROGRAMRUNNER_H_
#define CONSOLEPROGRAMRUNNER_H_

#include "program_runner.h"

namespace Base {

class ConsoleProgramRunner : public ProgramRunner {
 public:
  ConsoleProgramRunner();

  virtual ~ConsoleProgramRunner();

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

#endif /* CONSOLEPROGRAMRUNNER_H_ */
