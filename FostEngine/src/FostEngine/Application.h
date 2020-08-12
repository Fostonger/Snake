#pragma once
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace Fost {

	class Application 
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClosedEvent(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		static Application* s_Instance;
	};

	//defined in a game
	Application* CreateApplication();
}