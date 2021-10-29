#pragma once

#include "Iridpch.h"

#include "Exports.h"
#include "spdlog/spdlog.h"

namespace Iridescent {

    class IRID_EXPORT Log
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

// Core log macros
#define IRID_CORE_TRACE(...)    ::Iridescent::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define IRID_CORE_INFO(...)     ::Iridescent::Log::GetCoreLogger()->info(__VA_ARGS__)
#define IRID_CORE_WARN(...)     ::Iridescent::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define IRID_CORE_ERROR(...)    ::Iridescent::Log::GetCoreLogger()->error(__VA_ARGS__)
#define IRID_CORE_CRITICAL(...) ::Iridescent::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define IRID_TRACE(...)         ::Iridescent::Log::GetClientLogger()->trace(__VA_ARGS__)
#define IRID_INFO(...)          ::Iridescent::Log::GetClientLogger()->info(__VA_ARGS__)
#define IRID_WARN(...)          ::Iridescent::Log::GetClientLogger()->warn(__VA_ARGS__)
#define IRID_ERROR(...)         ::Iridescent::Log::GetClientLogger()->error(__VA_ARGS__)
#define IRID_CRITICAL(...)      ::Iridescent::Log::GetClientLogger()->critical(__VA_ARGS__)