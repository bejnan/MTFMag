#pragma once

#include "judge.h"


using std::function;

namespace Tools {

class DeviationJudge: public Judge {
public:
	DeviationJudge(function<int(int, int)> expectedResultFunction, function<int(int,int)> expectedThreshold);
	virtual ~DeviationJudge();
	virtual void CountPenalty(unsigned int element_position) = 0;
	virtual unsigned long OveralPenalty() = 0;
	virtual vector<pair<int, int> > PenaltyDetails() = 0;
	virtual shared_ptr<Judge> Clone() = 0;
private :
	function<int(int, int)> m_expectedResult;
	function<int(int, int)> m_threshold;
};

} /* namespace Tools */
