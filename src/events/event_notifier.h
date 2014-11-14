#pragma once

#include "event_listener.h"
#include <vector>

namespace Utils {

class EventNotifier {
public:
	void addListener(std::shared_ptr<EventListener> notifier);
	void removeListener(std::shared_ptr<EventListener> notifier);
	void notify(Base::Result result);
private :
	std::vector<std::shared_ptr<EventListener> > listeners;
};

typedef std::shared_ptr<EventNotifier> EventNotifierPtr;

} /* namespace Utils */
