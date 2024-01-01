#include "CLogger.h"
#include <LoggerDefines.h>

CLogger *CLogger::s_instance = nullptr;
CLogger *CLogger::instance()
{

    return s_instance = (s_instance == nullptr)? new CLogger(): s_instance;

}

CLogger::CLogger()
{}

CLogger::~CLogger()
{}
