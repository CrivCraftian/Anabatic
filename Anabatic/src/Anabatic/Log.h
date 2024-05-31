#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Anabatic
{
	class AN_API Log
	{
		public:
			static void Init();

			inline static std::shared_ptr < spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core Log macros
#define AN_CORE_ERROR(...)  ::Anabatic::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AN_CORE_WARN(...)   ::Anabatic::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AN_CORE_INFO(...)   ::Anabatic::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AN_CORE_TRACE(...)  ::Anabatic::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AN_CORE_FATAL(...)  ::Anabatic::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define AN_ERROR(...)  ::Anabatic::Log::GetClientLogger()->error(__VA_ARGS__)
#define AN_WARN(...)   ::Anabatic::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AN_INFO(...)   ::Anabatic::Log::GetClientLogger()->info(__VA_ARGS__)
#define AN_TRACE(...)  ::Anabatic::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AN_FATAL(...)  ::Anabatic::Log::GetClientLogger()->fatal(__VA_ARGS__)