#ifndef STRUCTSDEF_H
#define STRUCTSDEF_H

#include "Math/math2D.h"

typedef struct Size
{
    int width, height;
} Size;

typedef struct SizeF
{
    float width, height;
} SizeF;



// tile map objects
typedef struct Layer
{
    int id;
    const char *name;
    int width, height;
    bool visible;
    Matrix2D<int> data;
} Layer;

typedef struct Object
{
    int id;
    float x, y;
    float width, height;
    const char *shape;
    std::vector<Point2DF> vertices;
} Object;

typedef struct ObjectLayer
{
    int id;
    const char *name;
    const char *color;
    std::vector<Object> objects;
} ObjectLayer;

typedef struct GroupLayer
{
    int id;
    const char *name;
    std::vector<Layer> layers;
    std::vector<ObjectLayer> objectLayers;
} GroupLayer;

typedef struct Image
{
    const char *src;
    float width, height;
} Image;

typedef struct Tile
{
    char *src;
    Point2DI position;
    float width, height;
} Tile;


typedef struct TileSet
{
    int firstgid;
    const char *name;
    float tileWidth, tileHeight;
    int count, columns, rows;
    Image image;
} TileSet;


#endif // STRUCTSDEF_H
