#include "pch.h"
#include <FairyIsland/Log.h>
#include "WindowsGLFWWindow.h"

namespace FI
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsGLFWWindow(props);
	}

	WindowsGLFWWindow::WindowsGLFWWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsGLFWWindow::~WindowsGLFWWindow()
	{

	}

	void WindowsGLFWWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		FI_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			// TODO: glfw窗口资源销毁
			int success = glfwInit();
			//FI_CORE_ASSERT(success, "Could Not Initialize GLFW!");
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsGLFWWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsGLFWWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsGLFWWindow::SetVSync(bool enable)
	{
		glfwSwapInterval((int)enable);
		m_Data.VSync = enable;
	}

	bool WindowsGLFWWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}