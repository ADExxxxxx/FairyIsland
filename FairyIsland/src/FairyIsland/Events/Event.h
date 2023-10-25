#pragma once

#include "FairyIsland/Core.h"
#include <string>
#include <functional>

namespace FI
{
	enum class EventType
	{
		None = 0,
		
		// Windows Event
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,
		
		// Application Event
		AppTick,
		AppUpdate,
		AppRender,

		// Keyboard Event
		KeyPressed,
		KeyReleased,

		// Mouse Event
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication		= BIT(0),
		EventCategoryInput				= BIT(1),
		EventCategoryKeyboard			= BIT(2),
		EventCategoryMouse				= BIT(3),
		EventCategoryMouseButton		= BIT(4)
	};


#define EVENT_CLASS_TYPE(type) \
static EventType GetStaticType() { return EventType::##type; } \
virtual EventType GetEventType() const override { return GetStaticType(); } \
virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATRGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class FAIRY_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		bool m_Handled = false;
	};


	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
		{

		}

	};
}