#pragma once

#include "Core.h"

#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#pragma warning(pop)

namespace FI
{
	class FAIRY_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }

		~Log();
		Log();

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
// 
#define FI_CORE_ERROR(...)		::FI::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FI_CORE_WARN(...)		::FI::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FI_CORE_INFO(...)		::FI::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FI_CORE_TRACE(...)		::FI::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FI_CORE_FATAL(...)		::FI::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define FI_ERROR(...)			::FI::Log::GetClientLogger()->error(__VA_ARGS__)
#define FI_WARN(...)			::FI::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FI_INFO(...)			::FI::Log::GetClientLogger()->info(__VA_ARGS__)
#define FI_TRACE(...)			::FI::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FI_FATAL(...)			::FI::Log::GetClientLogger()->fatal(__VA_ARGS__)