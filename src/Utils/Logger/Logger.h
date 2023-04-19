#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <memory>
#include <stdexcept>
#include "Defines/EnumDef.h"

/** @brief Indicates if warning level logging is enabled. */
#define LOG_WARN_ENABLED 1
/** @brief Indicates if info level logging is enabled. */
#define LOG_INFO_ENABLED 1
/** @brief Indicates if debug level logging is enabled. */
#define LOG_DEBUG_ENABLED 1
/** @brief Indicates if trace level logging is enabled. */
#define LOG_TRACE_ENABLED 1

// Disable debug and trace logging for release builds.
#if ORELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

template<typename ...TArgs>
void log_output(LOG_LEVEL level, const char* fn, int line, const char *format, TArgs... args)
{
    // TODO: These string operations are all pretty slow. This needs to be
    // moved to another thread eventually, along with the file writes, to
    // avoid slowing things down while the engine is trying to run.
    const char* level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]:  ", "[INFO]:  ", "[DEBUG]: ", "[TRACE]: "};

    time_t now = time(nullptr);
    tm *localTime = localtime(&now);

    int size_s = std::snprintf( nullptr, 0, format, args ... ) + 1; // Extra space for '\0'
    if( size_s <= 0 ){ throw std::runtime_error( "Error during formatting." ); }
    auto size = static_cast<size_t>( size_s );
    std::unique_ptr<char[]> buff( new char[ size ] );
    std::snprintf( buff.get(), size, format, args ... );
    std::cout << "[" << std::put_time(localTime, "%Y-%m-%d %H:%M:%S") << "]"
              << level_strings[level]
              << std::string( buff.get(), buff.get() + size - 1 ).c_str()
              << "\t\[" << fn << "]"
              << "[" << line << "]"
              << '\n';
}

/**
 * @brief Logs a fatal-level message. Should be used to stop the application when hit.
 * @param message The message to be logged. Can be a format string for additional parameters.
 * @param ... Additional parameters to be logged.
 */
#define LOG_FATAL(message, ...) log_output(LOG_LEVEL::FATAL, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);

#ifndef KERROR
/**
 * @brief Logs an error-level message. Should be used to indicate critical runtime problems
 * that cause the application to run improperly or not at all.
 * @param message The message to be logged.
 * @param ... Any formatted data that should be included in the log entry.
 */
#define LOG_ERROR(message, ...) log_output(LOG_LEVEL::ERROR, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
/**
 * @brief Logs a warning-level message. Should be used to indicate non-critial problems with
 * the application that cause it to run suboptimally.
 * @param message The message to be logged.
 * @param ... Any formatted data that should be included in the log entry.
 */
#define LOG_WARN(message, ...) log_output(LOG_LEVEL::WARN, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#else
/**
 * @brief Logs a warning-level message. Should be used to indicate non-critial problems with
 * the application that cause it to run suboptimally. Does nothing when LOG_WARN_ENABLED != 1
 * @param message The message to be logged.
 * @param ... Any formatted data that should be included in the log entry.
 */
#define LOG_WARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
/**
 * @brief Logs an info-level message. Should be used for non-erronuous informational purposes.
 * @param message The message to be logged.
 * @param ... Any formatted data that should be included in the log entry.
 */
#define LOG_INFO(message, ...) log_output(LOG_LEVEL::INFO, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#else
/**
 * @brief Logs an info-level message. Should be used for non-erronuous informational purposes.
 * Does nothing when LOG_INFO_ENABLED != 1
 * @param message The message to be logged.
 * @param ... Any formatted data that should be included in the log entry.
 */
#define LOG_INFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
/**
 * @brief Logs a debug-level message. Should be used for debugging purposes.
 * @param message The message to be logged.
 * @param ... Any formatted data that should be included in the log entry.
 */
#define LOG_DEBUG(message, ...) log_output(LOG_LEVEL::DEBUG, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#else
/**
 * @brief Logs a debug-level message. Should be used for debugging purposes.
 * Does nothing when LOG_DEBUG_ENABLED != 1
 * @param message The message to be logged.
 * @param ... Any formatted data that should be included in the log entry.
 */
#define LOG_DEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
/**
 * @brief Logs a trace-level message. Should be used for verbose debugging purposes.
 * @param message The message to be logged.
 * @param ... Any formatted data that should be included in the log entry.
 */
#define LOG_TRACE(message, ...) log_output(LOG_LEVEL::TRACE, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#else
/**
 * @brief Logs a trace-level message. Should be used for verbose debugging purposes.
 * Does nothing when LOG_TRACE_ENABLED != 1
 * @param message The message to be logged.
 * @param ... Any formatted data that should be included in the log entry.
 */
#define LOG_TRACE(message, ...)
#endif

class Logger
{
public:
    Logger();

    Logger &begin();

private:
//    LOG_LEVEL m_level;
//    std::ostream m_out;

};

#endif // LOGGER_H
