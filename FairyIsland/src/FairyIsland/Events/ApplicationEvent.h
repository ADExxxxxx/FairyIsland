#pragma once

#include "Event.h"

namespace FI
{
	class FAIRY_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)


	private:
		unsigned int m_Width, m_Height;
	};
}