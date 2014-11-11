#include "processor.h"
namespace Tools {

Processor::Processor(int user_id, shared_ptr<Judge> judge,
                     shared_ptr<Algorithms::Algorithm> algorithm)
    : user_id_(user_id),
      penalty_judge_(judge),
      algorithm_(algorithm) {
}

Processor::~Processor() {
}

void Processor::Proceed(int user_id, bool learn) {
  if (!(algorithm_)->HaveElement(user_id)) {
    (algorithm_)->AddElement(user_id);
  }
  if (!learn) {
    int position = (algorithm_)->GetContentPosition(user_id);
    (penalty_judge_)->CountPenalty(position);
    notify(createResult(user_id));
  }
  algorithm_->NotifyContent(user_id);
}

string Processor::AlgorithmName() {
  return algorithm_->GetAlgorithmName();
}

int Processor::GetPenalty()
{
	return penalty_judge_->OveralPenalty();
}

Base::Result Processor::createResult(int user_id) {
	return Base::Result(AlgorithmName(),user_id, penalty_judge_->OveralPenalty(), 0 /*TODO*/);
}

} /* Namespace Tools */

