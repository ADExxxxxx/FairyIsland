#pragma once

#include <FairyIsland/Input.h>

namespace FI
{
	
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode);

		bool IsMouseButtonPressedImpl(int button) override;
		float GetMouseXImpl() override;
		float GetMouseYImpl() override;
		virtual std::pair<float, float> GetMousePositionImpl() override;

	};

}

