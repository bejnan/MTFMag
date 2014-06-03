#ifndef CONFIG_H_
#define CONFIG_H_
#include <vector>
#include <memory>
#include <initializer_list>

#include "../../headers/algorithms.h"
#include "../../headers/tools.h"
#include "../../headers/elements.h"

using std::shared_ptr;
using std::initializer_list;

namespace Base {

/**
 * Container of data needed to prepare all class instances and make
 * program runnable. It is used by ResultCollectorBuilder to create
 * ResultCollector with all it's dependencies.
 */
class Configuration {
 public:

  /**
   * Enum describing input of data for DataCollector.
   * Every value referees to DataProvider subclass
   * @see DataCollector
   */
  enum DataInput {
    ConsoleDataInput = 1,  //!< ConsoleDataInput - TODO Implementation doesn't exists
    FileDataInput        //!< FileDataInput - Referees to FileDataProvider
  };

  /**
   * Enum describing output of data for DataCollector.
   * Every value referees to DataOutput subclass
   */
  enum DataOutput {
    CSVConsoleDataOutput,  //!< CSVConsoleDataOutput - Referees to CsvDataOutput
    CSVFileDataOoutput,  //!< CSVFileDataOoutput - Referees to CsvFileDataOutput
  };

  /**
   * Enum describing chosen Judge implementation.
   */
  enum JudgeSelection {
    Tester = 1  //!< Tester
  };

  /**
   * Default constructor. Initialize every "safe" property with default value.
   * By "safe" I mean no empty pointers or unreachable data.
   */
  Configuration();

  /**
   * Empty destructor. Nothing to handle.
   */
  virtual ~Configuration();

  /**
   * Adds name of algorithm that should be used in program
   * @param algorithm_name Name of algorithm
   */
  void AddAlgorithm(string algorithm_name);

  /**
   * Sets set of names of algorithms that should be used in program.
   * @param algorithms
   */
  void SetAlgorithms(vector<string> algorithms);

  /**
   * Getter of algorithm prototypes sets by their names
   * @return vector of pointers to algorithm instances the same as names added by
   * AddAlgorithm or SetAlgorithms
   */
  vector<shared_ptr<Algorithms::Algorithm> > algorithm() {
    return algorithms_;
  }

  /**
   * Getter of Base::Element prototype
   * @return Prototype of Base::Element for all chosen algorithm
   */
  shared_ptr<Base::Element> GetElementPrototype();

  /**
   * Setter of Base::Element prototype for chosen algorithm.
   * Important to set prototype before setting algorithms.
   * @param element_prototype Instance of Base::Element class to use as prototype
   * for algorithms.
   */
  void SetElementPrototype(shared_ptr<Base::Element> element_prototype);

  /**
   * Getter of chosen input method for program
   * @return DataInput value
   */
  DataInput GetDataInputMethod() const;

  /**
   * Setter of input method for program
   * @param data_input_method DataInput value describing input
   */
  void SetDataInputMethod(DataInput data_input_method);

  /**
   * Getter of output method for program.
   * @return DataOutput value describing instance of Base::DataOutput class.
   */
  DataOutput GetDataOutputMethod() const;

  /**
   * Setter of output method for program
   * @param data_output_method DataOutput value describing instance of Base::DataOutput class
   */
  void SetDataOutputMethod(DataOutput data_output_method);

  /**
   * Getter of JudgeSelection value.
   * @return JudgeSelection value describing instance of Tools::Judge class.
   */
  JudgeSelection GetJudgeSelection() const;

  /**
   * Setter of JudgeSelection value describing instance of Tools::Judge class to generate.
   * @param judge_selection JudgeSelection value describing instance of Tools::Judge class.
   */
  void SetJudgeSelection(JudgeSelection judge_selection);

  /**
   * Returns number of positions with no penalty.
   * @return Number of positions with no penalty during notification
   */
  int GetJudgeFreePositionRange() const;

  /**
   * Setter of number of position with no penalty.
   * @param judge_free_position_range Number of positions with no penalty
   */
  void SetJudgeFreePositionRange(int judge_free_position_range);

  /**
   * Getter of number of positions with counted penalty.
   * Penalty counting algorithm depends on Tools::Judge implementation
   * @return Number of position with counted penalty
   * @see Tools::Judge
   */
  int GetJudgeSmallPenaltyPositionRange() const;

  /**
   * Setter of number of positions with counted penalty.
   * Penalty counting algorithm depends on Tools::Judge implementation
   * @param judge_small_penalty_position_range Number of positions with counted penalty
   * @see Tools:Judge
   */
  void SetJudgeSmallPenaltyPositionRange(
      int judge_small_penalty_position_range);

  /**
   * Getter of number of turns (input lines) without counting penalty for algorithms.
   * @return Number of turns that program can use to learn itself without penalty.
   */
  int GetLearnTurns() const;

  /**
   * Setter if number of turns (input lines) without counting penalty for algorithms.
   * @param learn_turns Number of turns that program can use to learn itself without penalty.
   */
  void SetLearnTurns(int learn_turns);

  /**
   * Getter of number of turns (input lines) with normal penalty counting
   * @return Number of turns (input lines) with normal penalty counting
   */
  int GetRunTurns() const;

  /**
   * Setter of number of turns (input lines) with normal penalty counting
   * @param run_turns Number of turns (input lines) with normal penalty counting
   */
  void SetRunTurns(int run_turns);

  /**
   * Getter of path to file with input data (if there is any).
   * Use of file depends if DataInput indicates DataProvider instance that uses file.
   * @return Path to file with input data
   */
  const string& GetDataInputFile() const;

  /**
   * Setter of path to input file (if there is any).
   * Use of file depends if DataInput indicates DataProvider instance that uses file.
   * @param data_input_file Path to input file
   */
  void SetDataInputFile(const string& data_input_file);

  /**
   * Getter of path to output file (if there is any).
   * Use of file depends on if DataOutput indicates DataOutput instance that uses file.
   * @return Path to output file
   */
  const string& GetDataOutputFile() const;

  /**
   * Setter of path to output file (if there is any)
   * Use of file depends on if DataOutput indicates DataOutput instance that uses file.
   * @param data_output_file Path to output file
   */
  void SetDataOutputFile(const string& data_output_file);

 private:
  /** Collection of Algorithms::Algorithm instances created by algorithms names given by
   * AddAlgorithm() and SetAlgorithm() methods  */
  vector<shared_ptr<Algorithms::Algorithm> > algorithms_;

  /** Pointer to prototype of Base::Element instance that should be used in algorithms */
  shared_ptr<Base::Element> element_prototype_;

  /** Property with chosen method of providing data for program   */
  DataInput data_input_method_;

  /** Property with chosen method of data output */
  DataOutput data_output_method_;

  /** Property indicating Tools::Judge to use in JudgeCollector */
  JudgeSelection judge_selection_;

  /** Property with number of positions with no penalty */
  int judge_free_position_range_;
  /** Property with number of positions with couted penalty */
  int judge_small_penalty_position_range_;

  /** Number of turns (input lines) program analise without penalty */
  int learn_turns_;

  /** Number of turns (input lines) program runs with penalty counting */
  int run_turns_;

  /** Path of input file (if needed) */
  string data_input_file_;
  /** Path of output file (if needed) */
  string data_output_file_;
};

} /* namespace Base */

#endif /* CONFIG_H_ */
