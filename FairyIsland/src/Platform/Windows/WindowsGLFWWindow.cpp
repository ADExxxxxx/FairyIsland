#include "pch.h"
#include <FairyIsland/Log.h>
#include <FairyIsland/Events/ApplicationEvent.h>
#include <FairyIsland/Events/KeyEvent.h>
#include <FairyIsland/Events/MouseEvent.h>

#include <Glad/glad.h>
#include <GLFW/glfw3.h>

#include "WindowsGLFWWindow.h"

namespace FI
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallBack(int error_code, const char* description)
	{
		FI_CORE_ERROR("GLFW Error ({0}): {1}", error_code, description);
	}

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
			FI_CORE_ASSERT(success, "Could Not Initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallBack);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);

		// 创建OpenGL
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		FI_CORE_ASSERT(status, "Failed to initialize Glad!");

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// glfw callbacks
		// 窗口大小变化
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;
			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		// 关闭窗口
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		// 键盘事件
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, 0);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key);
				data.EventCallback(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent event(key, 1);
				data.EventCallback(event);
				break;
			}
			default:
				break;
			}
		});

		// 鼠标点击事件
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
				break;
			}
			default:
				break;
			}
		});

		// 滚轮滑动
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xoffset, (float)yoffset);
			data.EventCallback(event);
		});

		// 鼠标移动
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((float)xpos, (float)ypos);
			data.EventCallback(event);
		});
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