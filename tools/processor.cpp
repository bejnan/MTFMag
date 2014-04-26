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

void Processor::Proceed(int user_id, bool learn = false) {
  if (!(algorithm_)->HaveElement(user_id)) {
    (algorithm_)->AddElement(user_id);
  }
  if (!learn) {
    int position = (algorithm_)->GetContentPosition(user_id);
    (penalty_judge_)->CountPenalty(position);
  }
  algorithm_->NotifyContent(user_id);
}

int Processor::GetPenalty() {
  return (penalty_judge_)->OveralPenalty();
}

string Processor::AlgorithmName() {
  return (algorithm_)->AlgorithmName();
}

} /* Namespace Tools */

