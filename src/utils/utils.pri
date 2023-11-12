HEADERS += \
    $$PWD/Logger/CLogger.h \
    $$PWD/Logger/LoggerDefines.h \
    $$PWD/Memory/LFUCache/CLFUCache.h \
    $$PWD/Memory/LRUCache/CLRUCache.h \
    $$PWD/Process/ThreadPool/CThreadPool.h \
    $$PWD/Utils.h

SOURCES += \
    $$PWD/Logger/CLogger.cpp \
    $$PWD/Memory/LFUCache/CLFUCache.cpp \
    $$PWD/Memory/LRUCache/CLRUCache.cpp \
    $$PWD/Process/ThreadPool/CThreadPool.cpp



INCLUDEPATH += \
    $$PWD/Logger \
    $$PWD/Memory \
    $$PWD
