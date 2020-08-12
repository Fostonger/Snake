#pragma once
#include "spdlog/spdlog.h"

namespace Fost {
	
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()   { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define FOST_CORE_INFO(...)    ::Fost::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FOST_CORE_TRACE(...)   ::Fost::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FOST_CORE_WARN(...)    ::Fost::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FOST_CORE_ERROR(...)   ::Fost::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FOST_CORE_FATAL(...)   ::Fost::Log::GetCoreLogger()->fatal(__VA_ARGS__)
							   
//Client log macros			   
#define FOST_FATAL(...)        ::Fost::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define FOST_INFO(...)         ::Fost::Log::GetClientLogger()->info(__VA_ARGS__)
#define FOST_ERROR(...)        ::Fost::Log::GetClientLogger()->error(__VA_ARGS__)
#define FOST_TRACE(...)        ::Fost::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FOST_WARN(...)         ::Fost::Log::GetClientLogger()->warn(__VA_ARGS__)

