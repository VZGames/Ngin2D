TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

include(src/engine/engine.pri)
include(src/utils/utils.pri)
include(src/scripts/scripts.pri)

SOURCES += \
    src/main.cpp


# Set include and library directories based on the platform
INCLUDE_DIR = $$PWD/include
LIBRARY_DIR = $$PWD/libs
BINARY_DIR  = $$PWD/bin

# Copy dynamic libraries
#LIB_DEST_DIR = $$OUT_PWD/debug
#QMAKE_POST_LINK += \
#    $$quote(copy /Y $$shell_path($$BINARY_DIR/SDL2.dll) $$shell_path($$LIB_DEST_DIR)) \
#    $$quote(copy /Y $$shell_path($$BINARY_DIR/SDL2_image.dll) $$shell_path($$LIB_DEST_DIR)) \
#    $$quote(copy /Y $$shell_path($$BINARY_DIR/TinyXML2.dll) $$shell_path($$LIB_DEST_DIR)) \


# Set linker libraries for Windows
LIBS += \
    -lmingw32 \
    -L$$PWD/libs \
    -lSDL2main \
    -lSDL2 \
    -lSDL2_image \
    -lbox2d \
    -lTinyXML2


INCLUDEPATH += \
    $$INCLUDE_DIR \
    $$PWD

