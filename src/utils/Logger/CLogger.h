#ifndef CLOGGER_H_
#define CLOGGER_H_

#include <string>
#include <sstream>
#include <mutex>
#include <thread>
#include "Utils.h"
#include "CommonEnums.h"

class CLogger
{
public:
    static CLogger *instance();

    template <typename... TArgs>
    void log(const E_LOGGER_LEVEL &level, const char *file, const char *fn, const uint32_t &line, const char *fm, TArgs... args)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        std::string lv = dec64ToASCII(level);
        time_t now = time(nullptr);
        tm *localTime = localtime(&now);
        char time_str[100];
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localTime);

        printf("[%s][%s][%s][fn: %s, line: %d]\t", time_str, lv.c_str(), file, fn, line);
        printf(fm, args...);
        printf("\n");

        fflush(stdout);
    }

private:
    explicit CLogger();
    ~CLogger();

private:
    static CLogger *s_instance;
    std::mutex m_mutex;
};

#endif // CLOGGER_H_
