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
 * Class containing configuration of program. Changes input flags, text, data to
 * objects needed to run program.
 */
class Configuration {
 public:

  enum DataInput {
    ConsoleDataInput = 1,
    CSVDataInput,
    CSVFileDataInput
  };

  enum DataOutput {
    ConsoleDataOutput,
    FileDataOoutput
  };
  Configuration();
  virtual ~Configuration();

  void AddAlgorithms(initializer_list<string> algorithms);

  void SetDataInput(DataInput dataInputMethod);

  void SetDataOutput();

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
