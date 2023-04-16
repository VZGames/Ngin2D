#ifndef LOGLEVELDEF_H
#define LOGLEVELDEF_H

typedef enum TYPE_SHAPE
{
    ELLIPSE = 0,
    RECTANGLE,
    POLYGON
} TYPE_SHAPE;

typedef enum LOG_LEVEL
{
    FATAL = POLYGON + 1,
    ERROR,
    WARN,
    INFO,
    DEBUG,
    TRACE
} LOG_LEVEL;

#endif // LOGLEVELDEF_H
