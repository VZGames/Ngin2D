#ifndef TILEMAP_DEFINE_H
#define TILEMAP_DEFINE_H

#include <stdint.h>

typedef struct
{
    const char* version;
    const char* tiled_version;
    const char* render_order;
    int         width;
    int         height;
    int         tile_width;
    int         tile_height;
    int         next_layer_id;
    int         next_object_id;
    bool        infinite;
} TmxMap;

typedef struct
{
    int         first_global_id;
    const char* name;
    int         tile_count;
    int         tile_width;
    int         tile_height;
    int         margin;
    int         spacing;
    int         columns;

} TmxTileSet;

typedef struct
{
    const char* format;
    const char* source;
    int         width;
    int         height;
} TmxImage;

typedef struct
{
    int         id;
    const char* name;
    int         x;
    int         y;
    int         width;
    int         height;
    float       opacity;
    bool        visible;
    int         offset_x;
    int         offset_y;
} TmxLayer;

typedef struct
{
    const char* encoding;
    const char* compression;
    const char* content;
} TmxData;

#endif // TILEMAP_DEFINE_H
