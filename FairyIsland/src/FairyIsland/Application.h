#pragma once
#include "Core.h"
#include <FairyIsland/Window.h>

#include <FairyIsland/Events/Event.h>
#include <FairyIsland/Events/ApplicationEvent.h>

#include <FairyIsland/LayerStack.h>

namespace FI 
{

	class FAIRY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
	};


	Application* CreateApplication();
}

