#pragma once

#include <FairyIsland/Layer.h>
#include <FairyIsland/Events/MouseEvent.h>
#include <FairyIsland/Events/KeyEvent.h>
#include <FairyIsland/Events/ApplicationEvent.h>

namespace FI
{
	class FAIRY_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate();
		void OnDetach();
		void OnAttach();
		void OnEvent(Event& event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMoveEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizedEvent(WindowResizeEvent& e);


	private:
		float m_Time =0.0f;
	};
}

