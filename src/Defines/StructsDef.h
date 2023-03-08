#ifndef STRUCTSDEF_H
#define STRUCTSDEF_H

#include "../Math/math2D.h"

typedef struct Size
{
    int width, height;
} Size;


// tile map objects
typedef struct Layer
{
    int id;
    const char *name;
    int width, height;
    Matrix2D<int> data;
} Layer;

typedef struct GroupLayer
{
    int id;
    const char *name;
    std::vector<Layer> layers;
} GroupLayer;

typedef struct Image
{
    const char *src;
    int width, height;
} Image;

typedef struct Tile
{
    char *src;
    Point2DI position;
    int width, height;
} Tile;


typedef struct TileSet
{
    int firstgid;
    const char *name;
    int tileWidth, tileHeight;
    int count, columns, rows;
    Image image;
} TileSet;


#endif // STRUCTSDEF_H
