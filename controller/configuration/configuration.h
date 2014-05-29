/*
 * config.h
 *
 *  Created on: May 28, 2014
 *      Author: kuba
 */

#ifndef CONFIG_H_
#define CONFIG_H_
#include <vector>
#include <memory>
#include <initializer_list>

#include "../headers/algorithms.h"
#include "../headers/data_managment.h"
#include "../headers/tools.h"


using std::shared_ptr;
using std::initializer_list;

namespace Base {

/**
 * Class containing configuration of program. Changes input data to
 * flags, objects or instructions to run program.
 */
class Configuration {
 public:

  enum DataInput {
    ConsoleDataInput = 1,
    FileDataInput
  };

  enum DataOutput {
    ConsoleDataOutput,
    CSVFileDataOoutput,
  };


  Configuration();
  virtual ~Configuration();

  void AddAlgorithms(initializer_list<string> algorithms);

  void SetDataInput(DataInput data_iput_method);

  void SetDataOutput(DataOutput data_output_method);

  void SetDataInputFilePath(string path);

  void SetDataOutputFilePath(string path);

  void Run();

  vector<shared_ptr<Algorithms::Algorithm> > algorithm() {
    return algorithms_;
  }

  shared_ptr<Tools::Judge> judge() {
    return judge_;
  }

 private:
  vector<shared_ptr<Algorithms::Algorithm> > algorithms_;
  shared_ptr<Tools::Judge> judge_;
};

} /* namespace Base */

#endif /* CONFIG_H_ */
