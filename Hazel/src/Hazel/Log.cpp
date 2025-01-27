#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hazel {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	
	void Log::Init()
	{	
		// Set the pattern string (recommended):
		// set_pattern(pattern_string);
		// 
		// string:
		// %T: ISO 8601 time format (HH:MM:SS), equivalent to %H:%M:%S
		// %^: start color range (can be used only once)
		// %n: Logger's name
		// %v: The actual text to log
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// create a color multi-threaded logger
		s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}
