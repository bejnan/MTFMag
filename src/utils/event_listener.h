#pragma once

#include "../data_managment/results.h"

namespace Utils {

class EventListener {
public:
	virtual ~EventListener() { }
	virtual void handleEvent(Base::Result result) = 0;
};

} /* namespace Tools */
