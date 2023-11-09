#ifndef COMMONENUMS_H
#define COMMONENUMS_H

#include <cstdint>

enum E_CACHE_STATUS : bool
{
    HIT = true,
    MISS = false
};

enum E_DURATION : uint8_t
{
    NONE        = 0x0,
    IN_1_SEC    = 0x1,
    IN_2_SECS   = 0x2,
    IN_5_SECS   = 0x5,
    IN_10_SECS  = 0xA,
    IN_15_SEC   = 0xF,
    IN_30_SEC   = 0x1E
};

enum E_VIEW_TYPE : uint8_t
{
    NONE_TYPE = 0x0,
    SCREEN_TYPE = 0x1,
    POPUP_TYPE = 0x2,
    TOAST_TYPE = 0x3,
    NOTIFY_TYPE = 0x4
};

enum E_LOGGER_FLAG : uint64_t
{
    NOFLAG = 0x4E4F464C4147,
    QML = 0x514D4C,
    CPP = 0x435050
};

enum E_LOGGER_FLAG_COLOR : uint64_t
{

};

enum E_LOGGER_LEVEL : uint64_t
{
    FATAL = 0X464154414C,
    INFO = 0x494E464F,
    WARN = 0x5741524E,
    DEBUG = 0x4445425547,
    TRACE = 0x5452414345,
    ERROR = 0x4552524F52
};

enum E_LOGGER_LEVEL_COLOR : uint64_t
{

};

enum E_POPUP_PRIORITY_LEVEL
{
    LOW = 0,
    MEDIUM,
    HIGH
};

enum E_LOAD_SCENE_MODE
{
    SINGLE,
    ADDITIVE
};

enum E_CAMERA_ZOOM
{
    ZOOM_IN,
    ZOOM_OUT
};

enum E_BODY_TYPE
{
    STATIC = 0,
    DYNAMIC,
    KINEMATIC
};

enum E_SHAPE
{
    CIRCLE,
    POLYGON,
    EDGE,
    CHAIN
};

#endif // COMMONENUMS_H
