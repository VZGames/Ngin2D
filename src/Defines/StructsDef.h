#ifndef STRUCTSDEF_H
#define STRUCTSDEF_H

#include "../Math/math2D.h"

typedef struct Size
{
    int width, height;
} Size;


typedef struct Tile
{
    char *src;
    Point2D position;
    int width, height;
} Tile;


typedef struct TileSet
{
} TileSet;


#endif // STRUCTSDEF_H
