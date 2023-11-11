#include "CLogger.h"
#include "CommonDefine.h"


#define __LOG_INFO__    qInfo()
#define __LOG_WARN__    qWarning()
#define __LOG_FATAL__   qFatal()
#define __LOG_DEBUG__   qDebug()

#if 0
#define INFO(message, ...) NOTHING
#define WARN(message, ...) NOTHING
#define FATAL(message, ...) NOTHING
#define DBG(message, ...) NOTHING
#else
#define DBG(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::DEBUG, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#define INFO(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::INFO, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#define WARN(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::WARN, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#define FATAL(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::FATAL, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#endif

