HEADERS += \
    $$PWD/Logger/CLogger.h \
    $$PWD/Logger/LoggerDefines.h \
    $$PWD/Memory/LFUCache/CLFUCache.h \
    $$PWD/Memory/LRUCache/CLRUCache.h \
    $$PWD/Parser/XMLParser/CXmlParser.h \
    $$PWD/Process/CSafeQueue.h \
    $$PWD/Process/ThreadPool/CThreadPool.h \
    $$PWD/Process/ThreadPool/CThreadWorker.h \
    $$PWD/Utils.h

SOURCES += \
    $$PWD/Logger/CLogger.cpp \
    $$PWD/Memory/LFUCache/CLFUCache.cpp \
    $$PWD/Memory/LRUCache/CLRUCache.cpp \
    $$PWD/Parser/XMLParser/CXmlParser.cpp \
    $$PWD/Process/ThreadPool/CThreadPool.cpp \
    $$PWD/Process/ThreadPool/CThreadWorker.cpp



INCLUDEPATH += \
    $$PWD/Logger \
    $$PWD/Memory \
    $$PWD/Process \
    $$PWD/Parser \
    $$PWD
