#include "CLogger.h"
#include "CommonDefine.h"


#define __LOG_INFO__    qInfo()
#define __LOG_WARN__    qWarning()
#define __LOG_FATAL__   qFatal()
#define __LOG_DEBUG__   qDebug()

#if 0
#define MORGAN_INFO(message, ...) NOTHING
#define MORGAN_WARN(message, ...) NOTHING
#define MORGAN_FATAL(message, ...) NOTHING
#define MORGAN_DEBUG(message, ...) NOTHING
#else
#define MORGAN_DEBUG(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::DEBUG, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#define MORGAN_INFO(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::INFO, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#define MORGAN_WARN(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::WARN, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#define MORGAN_FATAL(message, ...) CLogger::instance()->log(E_LOGGER_LEVEL::FATAL, __FILENAME__, __FUNCTION__, __LINE__, message, ##__VA_ARGS__);
#endif

