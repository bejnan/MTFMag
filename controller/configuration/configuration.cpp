/*
 * config.cpp
 *
 *  Created on: May 28, 2014
 *      Author: kuba
 */

#include "configuration.h"

namespace Base {

Configuration::Configuration()
    : data_input_method_(ConsoleDataInput),
      data_output_method_(CSVConsoleDataOutput),
      judge_selection_(Tester),
      judge_free_position_range_(0),
      judge_small_penalty_position_range_(0)
{
}

Configuration::~Configuration() {
}

Configuration::DataInput Configuration::GetDataInputMethod() const {
  return data_input_method_;
}

void Configuration::SetDataInputMethod(DataInput data_input_method) {
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
