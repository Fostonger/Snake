#pragma once
#include <functional>
namespace Fost {
	enum class EventType
	{
		None = 0,
		KeyPressed, KeyReleased
	};
	class Event
	{
	public:
		bool Handled = false;

		virtual EventType GetEventType() = 0;
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool Dispatch(std::function<bool(T&)> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType()) 
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
}