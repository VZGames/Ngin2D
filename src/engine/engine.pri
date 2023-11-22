include($$PWD/Base/Base.pri)
include($$PWD/Common/Common.pri)
include($$PWD/Graphics/Graphics.pri)
include($$PWD/Math/Math.pri)
include($$PWD/ECS/ECS.pri)
include($$PWD/Scene/Scene.pri)
include($$PWD/World/World.pri)
include($$PWD/Control/Control.pri)
include($$PWD/System/System.pri)
include($$PWD/Adapters/Adapters.pri)
include($$PWD/Physics/Physics.pri)

INCLUDEPATH += \
    $$PWD/Base \
    $$PWD/Common \
    $$PWD/Graphics \
    $$PWD/Math \
    $$PWD/ECS \
    $$PWD/Scene \
    $$PWD/World \
    $$PWD/Control \
    $$PWD/System \
    $$PWD

HEADERS += \
    $$PWD/CNgin.h

SOURCES += \
    $$PWD/CNgin.cpp

