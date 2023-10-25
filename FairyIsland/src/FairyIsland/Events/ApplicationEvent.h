#pragma once

#include "Event.h"

namespace FI
{
	class FAIRY_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			// Todo: 自定义缓冲区
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << "," << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATRGORY(EventCategoryApplication);

	private:
		unsigned int m_Width, m_Height;
	};

	class FAIRY_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATRGORY(EventCategoryApplication);
	};

	class FAIRY_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATRGORY(EventCategoryApplication);
	};

	class FAIRY_API AppUpdateEvent : public Event
	{
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATRGORY(EventCategoryApplication);
	};

	class FAIRY_API AppRenderEvent : public Event
	{
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATRGORY(EventCategoryApplication);
	};
}