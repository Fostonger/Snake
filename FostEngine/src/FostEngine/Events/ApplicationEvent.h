#pragma once
#include "Event.h"

namespace Fost {

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {};

		EVENT_CLASS_TYPE(WindowClose);
	};
}