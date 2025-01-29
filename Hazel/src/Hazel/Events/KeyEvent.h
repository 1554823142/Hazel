#pragma once

#include "Event.h"

namespace Hazel {

	class HAZEL_API KeyEvent : public Event						// 设计keyevent基类的原因: 虽然按键事件是俩个不同的时间, 但是两者相似度较高
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class HAZEL_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeateCount)
			: KeyEvent(keycode), m_RepeateCount(repeateCount) {}

		inline int GetRepeatCount() const { return m_RepeateCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (repeats = " << m_RepeateCount << ")";
			return ss.str();
		}
		//使用宏防止重复写大量的代码: 
		// static EventType GetStaticType() { return EventType::KeyPressed; }
		// virtual EventType GetEventType() const override { return GetStaticType(); }
		// virtual const char* GetName() const override { return "KeyPressed"; }

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeateCount;
	};

	class HAZEL_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class HAZEL_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}