#pragma once
#include "Core.h"
#include <FairyIsland/Events/Event.h>
#include <FairyIsland/Window.h>

namespace FI 
{

	class FAIRY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
	};


	Application* CreateApplication();
}

