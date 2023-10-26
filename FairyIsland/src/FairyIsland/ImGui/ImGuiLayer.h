#pragma once

#include <FairyIsland/Layer.h>

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
		float m_Time;
	};
}

