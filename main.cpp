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
  Base::FileDataProvider file_data_provider(path);
  shared_ptr<Base::DataOutputBuilder> data_output_builder =
      Base::DataOutputBuilder::GetInstance();
  data_output_builder->SetCsvOutputFormat('|');
  Base::DataCollector dc(file_data_provider, data_output_builder->Generate());

  /* Set processor section */
  Algorithms::Algorithm* algorithm = new Algorithms::TreeRoot(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);
  Tools::ProcessorFactory* proc_fact = new Tools::ProcessorFactory(
      algorithm_ptr, judge_ptr);

  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(proc_fact));

  algorithm = new Algorithms::RandomTreeRoot(
      Base::SimpleElement::GetPrototype(), 0.2, 1);
  judge = new Tools::Tester(20, 20);
  algorithm_ptr = shared_ptr<Algorithms::Algorithm>(algorithm);
  judge_ptr = shared_ptr<Tools::Judge>(judge);
  proc_fact = new Tools::ProcessorFactory(algorithm_ptr, judge_ptr);

  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(proc_fact));

  algorithm = new Algorithms::MTFMatrix(Base::SimpleElement::GetPrototype());
  judge = new Tools::Tester(20, 20);
  algorithm_ptr = shared_ptr<Algorithms::Algorithm>(algorithm);
  judge_ptr = shared_ptr<Tools::Judge>(judge);
  proc_fact = new Tools::ProcessorFactory(algorithm_ptr, judge_ptr);

  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(proc_fact));

  algorithm = new Algorithms::MoveToFront(Base::SimpleElement::GetPrototype());
  judge = new Tools::Tester(20, 20);
  algorithm_ptr = shared_ptr<Algorithms::Algorithm>(algorithm);
  judge_ptr = shared_ptr<Tools::Judge>(judge);
  proc_fact = new Tools::ProcessorFactory(algorithm_ptr, judge_ptr);

  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(proc_fact));

  /* End of processors section */
  dc.RunTurns(learn_runs, true);

  for (int i = 0; i < test_runs / step_size; i++) {
    dc.RunTurns(step_size);
    dc.PrintActualResults();
  }
  int rest = test_runs - (test_runs / step_size) * step_size;
  if (rest > 0) {
    dc.RunTurns(rest);
    dc.PrintActualResults();
  }
  return 0;
}
