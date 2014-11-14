#include "event_notifier.h"
#include <algorithm>

namespace Utils {

void EventNotifier::addListener(std::shared_ptr<EventListener> listener)
{
	listeners.push_back(listener);
}

void EventNotifier::removeListener(std::shared_ptr<EventListener> listener)
{
	auto elementToRemove = std::find(listeners.begin(),listeners.end(), listener);
	if (elementToRemove != listeners.end())
		listeners.erase(elementToRemove);
}

void EventNotifier::notify(Base::Result result)
{
	auto notifier = [&result](std::shared_ptr<EventListener> listener) {listener->handleEvent(result);};
	std::for_each(listeners.begin(), listeners.end(), notifier);
}

} /* namespace Utils */
