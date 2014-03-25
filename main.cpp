/*
 * main.cpp
 *
 *  Created on: 25 lut 2014
 *      Author: kuba
 */
#include <string>
#include <cstdlib>
#include <iostream>
#include "Headers/DataManagment.h"
#include "Headers/Tools.h"

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
  FileDataProvider fdp(path);
  DataCollector dc(fdp);
  Tools::ProcessorFactory* proc_fact = new Tools::MTFProcessorFactory();
  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(proc_fact));

  proc_fact = new Tools::RandomTreeProcessorFactory();
  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(proc_fact));

  proc_fact = new Tools::RandomTreeProcessorFactory(0, 0);
  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(proc_fact));

  proc_fact = new Tools::RandomTreeProcessorFactory(0.25, 1);
  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(proc_fact));

  proc_fact = new Tools::TreeProcessorFactory();
  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(proc_fact));

  dc.RunTurns(learn_runs, true);
  vector<pair<string, int> > results;
  for (int i = 0; i < test_runs / step_size; i++) {
    dc.RunTurns(step_size);
    results = dc.GetResultsSum();
    cout << i * step_size << " ";
    for (vector<pair<string, int> >::iterator results_iter = results.begin();
        results_iter != results.end(); results_iter++) {
      cout << (*results_iter).first << " " << (*results_iter).second << " ";
    }
    cout << "\n";
  }
  int rest = test_runs - (test_runs / step_size) * step_size;
  if (rest > 0) {
    dc.RunTurns(rest);
    for (vector<pair<string, int> >::iterator results_iter = results.begin();
        results_iter != results.end(); results_iter++) {
      cout << (*results_iter).first << " " << (*results_iter).second << " ";
    }
    cout << "\n";
  }
  return 0;
}
