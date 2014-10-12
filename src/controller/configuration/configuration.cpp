#include "configuration.h"

namespace Base {

Configuration::Configuration()
    : data_input_method_(ConsoleDataInput),
      data_output_method_(CSVConsoleDataOutput),
      judge_selection_(Tester),
      judge_free_position_range_(0),
      judge_small_penalty_position_range_(0),
      learn_turns_(0),
      run_turns_(0) {
}

Configuration::~Configuration() {
}

void Configuration::AddAlgorithm(string algorithm_name) {
  algorithms_.push_back(
      Algorithms::AlgorithmContainer::GetInstance().GetAlgorithm(algorithm_name)->Clone());
}

void Configuration::SetAlgorithms(vector<string> algorithms) {
  algorithms_.clear();
  vector<string>::iterator names_iterator;
  for (names_iterator = algorithms.begin(); names_iterator != algorithms.end();
      names_iterator++) {
    algorithms_.push_back(
        Algorithms::AlgorithmContainer::GetInstance().GetAlgorithm(*(names_iterator))
            ->Clone());
  }
}

shared_ptr<Base::Element> Configuration::GetElementPrototype() {
  return element_prototype_;
}

void Configuration::SetElementPrototype(
    shared_ptr<Base::Element> element_prototype) {
  element_prototype_ = element_prototype;
}

Configuration::DataProvider Configuration::GetDataInputMethod() const {
  return data_input_method_;
}

void Configuration::SetDataInputMethod(DataProvider data_input_method) {
  data_input_method_ = data_input_method;
}

Configuration::DataOutput Configuration::GetDataOutputMethod() const {
  return data_output_method_;
}

void Configuration::SetDataOutputMethod(DataOutput data_output_method_) {
  this->data_output_method_ = data_output_method_;
}

Configuration::JudgeSelection Configuration::GetJudgeSelection() const {
  return judge_selection_;
}

int Configuration::GetJudgeFreePositionRange() const {
  return judge_free_position_range_;
}

void Configuration::SetJudgeFreePositionRange(int judge_free_position_range) {
  judge_free_position_range_ = judge_free_position_range;
}

void Configuration::SetJudgeSelection(JudgeSelection judge_selection) {
  judge_selection_ = judge_selection;
}

int Configuration::GetJudgeSmallPenaltyPositionRange() const {
  return judge_small_penalty_position_range_;
}

void Configuration::SetJudgeSmallPenaltyPositionRange(
    int judge_small_penalty_position_range) {
  judge_small_penalty_position_range_ = judge_small_penalty_position_range;
}

int Configuration::GetLearnTurns() const {
  return learn_turns_;
}

void Configuration::SetLearnTurns(int learn_turns) {
  this->learn_turns_ = learn_turns;
}

int Configuration::GetRunTurns() const {
  return run_turns_;
}

void Configuration::SetRunTurns(int run_turns) {
  this->run_turns_ = run_turns;
}

const string& Configuration::GetDataInputFile() const {
  return data_input_file_;
}

void Configuration::SetDataInputFile(const string& data_input_file) {
  data_input_file_ = data_input_file;
}

const string& Configuration::GetDataOutputFile() const {
  return data_output_file_;
}

void Configuration::SetDataOutputFile(const string& data_output_file) {
  data_output_file_ = data_output_file;
}

} /* namespace Base */
