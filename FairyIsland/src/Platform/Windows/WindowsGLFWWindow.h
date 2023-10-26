#pragma once

#include <FairyIsland/Window.h>

struct GLFWwindow;
namespace FI
{
	class WindowsGLFWWindow : public Window
	{
	public:
		WindowsGLFWWindow(const WindowProps& props);
		
		virtual ~WindowsGLFWWindow();

		virtual void OnUpdate() override;
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enable) override;
		bool IsVSync() const override;
		inline virtual void* GetNativeWindow() const override { return m_Window; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();

	private:
		GLFWwindow* m_Window;
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			EventCallbackFn EventCallback;
			bool VSync;
		};

		WindowData m_Data;
	};
}