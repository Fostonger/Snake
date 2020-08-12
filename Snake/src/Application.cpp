#include "fostpch.h"
#include "FostEngine/Application.h"
#include <GLFW/glfw3.h>

class Snaky : public Fost::Application 
{
public:
	Snaky() {};
	~Snaky(){};

};

extern Fost::Application* Fost::CreateApplication();
int main() 
{
	Fost::Log::Init();

	auto app = Fost::CreateApplication();
	app->Run();
	delete app;
}

Fost::Application* Fost::CreateApplication() 
{
	return new Snaky();
}