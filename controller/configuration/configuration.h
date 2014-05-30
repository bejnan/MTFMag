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

#include "../../headers/algorithms.h"
#include "../../headers/data_managment.h"
#include "../../headers/tools.h"

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
    CSVConsoleDataOutput,
    CSVFileDataOoutput,
  };

  enum JudgeSelection {
    Tester = 1
  };

  Configuration();
  virtual ~Configuration();

  void AddAlgorithms(initializer_list<string> algorithms);

  void Run();

  vector<shared_ptr<Algorithms::Algorithm> > algorithm() {
    return algorithms_;
  }

  shared_ptr<Tools::Judge> judge() {
    return judge_;
  }

  DataInput GetDataInputMethod() const;
  void SetDataInputMethod(DataInput data_input_method);

  DataOutput GetDataOutputMethod() const;
  void SetDataOutputMethod(DataOutput data_output_method);

  JudgeSelection GetJudgeSelection() const;
  void SetJudgeSelection(JudgeSelection judge_selection);

  int GetJudgeFreePositionRange() const;
  void SetJudgeFreePositionRange(int judge_free_position_range);

  int GetJudgeSmallPenaltyPositionRange() const;
  void SetJudgeSmallPenaltyPositionRange(
      int judge_small_penalty_position_range);

  const string& GetDataInputFile() const;
  void SetDataInputFile(const string& data_input_file);

  const string& GetDataOutputFile() const;
  void SetDataOutputFile(const string& data_output_file);


 private:
  vector<shared_ptr<Algorithms::Algorithm> > algorithms_;
  shared_ptr<Tools::Judge> judge_;
  DataInput data_input_method_;
  DataOutput data_output_method_;
  JudgeSelection judge_selection_;

  int judge_free_position_range_;
  int judge_small_penalty_position_range_;

  string data_input_file_;
  string data_output_file_;
};

} /* namespace Base */

#endif /* CONFIG_H_ */
