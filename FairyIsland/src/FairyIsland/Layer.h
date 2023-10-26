#pragma once

#include <FairyIsland/Core.h>
#include <FairyIsland/Events/Event.h>

namespace FI
{
	class FAIRY_API Layer
	{
	public:
		Layer(const std::string& name = "Layer") {};
		virtual ~Layer() {};

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}

