#pragma once
#include "Event.h"

namespace Fost {

	class KeyEvent : public Event 
	{
	public:
		inline int GetKeyCode() { return m_KeyCode; }

	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode)
			:KeyEvent(keycode) {}

		static EventType GetStaticType() { return EventType::KeyPressed; }
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			:KeyEvent(keycode) {}

		static EventType GetStaticType() { return EventType::KeyReleased; }
	};
}