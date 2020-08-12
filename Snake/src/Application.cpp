#include "fostpch.h"
#include <GLFW/glfw3.h>

int main() 
{
	Fost::Log::Init();
	Fost::Log::GetClientLogger()->info("Static library is fine, so is logging system");
}