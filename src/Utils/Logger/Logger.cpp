#include "Logger.h"

Logger *Logger::s_instance = nullptr;
Logger *Logger::instance()
{
    return s_instance = (s_instance == nullptr)? new Logger():s_instance;
}

Logger &Logger::info()
{
    time_t now = time(nullptr);
    tm *localTime = localtime(&now);

    m_out << "[" << std::put_time(localTime, "%Y-%m-%d %H:%M:%S") << "]"
              << level_strings[LOG_LEVEL::INFO];

    return *this;
}

Logger::Logger()
{
}
