#include "Logger.h"

void log_output(LOG_LEVEL level, const char *message, ...)
{
    // TODO: These string operations are all pretty slow. This needs to be
    // moved to another thread eventually, along with the file writes, to
    // avoid slowing things down while the engine is trying to run.
    const char* level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]:  ", "[INFO]:  ", "[DEBUG]: ", "[TRACE]: "};

//    std::ostream out = std::cout;
//    time_t now = time(nullptr);
//    tm *localTime = localtime(&now);

//    out << "[" << std::put_time(localTime, "%Y-%m-%d %H:%M:%S") << "] ";

}
