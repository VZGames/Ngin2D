#include "Logger.h"

Logger *Logger::s_instance = nullptr;
Logger *Logger::instance()
{
    return s_instance = (s_instance == nullptr)? new Logger():s_instance;
}

Logger &Logger::info()
{
    return *this;
}

Logger::Logger()
{

}
