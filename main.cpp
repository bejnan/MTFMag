/*
 * main.cpp
 *
 * Created on: 25 lut 2014
 * Author: Jakub Banaszewski
 */
#include <string>
#include <cstdlib>
#include <iostream>
#include "headers/data_managment.h"
#include "headers/tools.h"
#include "headers/controller.h"

using std::string;
using std::cout;

using namespace Base;

int main(int argc, char** argv) {
  int step_size = 1000;
  if (argc < 4)
    return -1;

  string path = string(argv[1]);
  int learn_runs = atoi(argv[2]);
  int test_runs = atoi(argv[3]);
  if (argc > 4) {
    step_size = atoi(argv[4]);
  }

  Base::Configuration configuration;

  configuration.SetElementPrototype(SimpleElement::GetPrototype());

  configuration.SetDataInputMethod(Configuration::DataInput::FileDataInput);
  configuration.SetDataInputFile(path);
  configuration.SetDataOutputMethod(
      Configuration::DataOutput::CSVConsoleDataOutput);
  configuration.SetJudgeFreePositionRange(20);
  configuration.SetJudgeSmallPenaltyPositionRange(20);
  configuration.SetLearnTurns(learn_runs);
  configuration.SetRunTurns(test_runs);

  configuration.AddAlgorithm(Algorithms::TreeRoot::AlgorithmName());
  configuration.AddAlgorithm(Algorithms::RandomTreeRoot::AlgorithmName());
  configuration.AddAlgorithm(Algorithms::MoveToFront::AlgorithmName());
  configuration.AddAlgorithm(Algorithms::MTFMatrix::AlgorithmName());

  Base::ResultCollectorBuilder result_builder;

  result_builder.SetConfig(configuration);

  shared_ptr<Base::ResultCollector> result_collector = result_builder.GenerateResultCollector();
  result_collector->SetTurns(learn_runs,test_runs);
  result_collector->SetResultFrequency(step_size);

  result_collector->Run();

}
