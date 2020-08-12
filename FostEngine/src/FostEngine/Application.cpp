#include "fostpch.h"
#include "Application.h"
#include <GLFW/glfw3.h>

namespace Fost {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;
	Application::Application()
	{
		FOST_CORE_ASSERT(!s_Instance, "Application is already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e) 
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClosedEvent));
	}

	void Application::Run() 
	{
		while (m_Running) 
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers((GLFWwindow*)m_Window->GetNativeWindow());
			glfwPollEvents();
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClosedEvent(WindowCloseEvent& e)
	{
		m_Running = false;

		return true;
	}
}
