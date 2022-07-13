#pragma once

#include <Dependencies.h>
#include "Hunchback\Core.h"

namespace Hunchback {

	class HUNCHBACK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Logging Macros

#define HNBK_CORE_TRACE(...) ::Hunchback::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HNBK_CORE_INFO(...) ::Hunchback::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HNBK_CORE_WARN(...) ::Hunchback::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HNBK_CORE_ERROR(...) ::Hunchback::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HNBK_CORE_FATAL(...) ::Hunchback::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define HNBK_TRACE(...) ::Hunchback::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HNBK_INFO(...) ::Hunchback::Log::GetClientLogger()->info(__VA_ARGS__)
#define HNBK_WARN(...) ::Hunchback::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HNBK_ERROR(...) ::Hunchback::Log::GetClientLogger()->error(__VA_ARGS__)
#define HNBK_FATAL(...) ::Hunchback::Log::GetClientLogger()->critical(__VA_ARGS__)
