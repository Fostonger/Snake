#include "WindowsWindow.h"

namespace Fost {
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}
	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}
	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Height = props.Height;
		m_Data.Width = props.Width;

		if (!s_GLFWInitialized) 
		{
			int succeed = glfwInit();
			if (!succeed)
				
			s_GLFWInitialized = true;
		}
	}
	void WindowsWindow::OnUpdate()
	{
	}
	void WindowsWindow::SetVSync(bool enabled)
	{
	}
	bool WindowsWindow::IsVSync() const
	{
		return false;
	}
	void WindowsWindow::Shutdown()
	{
	}
}