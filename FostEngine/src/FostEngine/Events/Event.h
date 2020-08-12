#pragma once
#include "fostpch.h"

namespace Fost {
	enum class EventType
	{
		None = 0,
		KeyPressed, KeyReleased,
		WindowClose
	};

#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() {return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }

	class Event
	{
	public:
		bool Handled = false;


		virtual EventType GetEventType() const = 0;
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