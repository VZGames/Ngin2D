#ifndef TILEMAP_DEFINE_H
#define TILEMAP_DEFINE_H

#include <stdint.h>

struct s_tmx_map;
struct s_tmx_image;
struct s_tmx_data;
struct s_tmx_layer;
struct s_tmx_tileset;

typedef struct s_tmx_map
{
    const char*             version;
    const char*             tiled_version;
    const char*             render_order;
    int                     width;
    int                     height;
    int                     tile_width;
    int                     tile_height;
    int                     next_layer_id;
    int                     next_object_id;
    bool                    infinite;
    s_tmx_tileset           *tilesets;
    s_tmx_layer             *layers;

} TmxMap;

typedef struct s_tmx_tileset
{
    int         first_global_id;
    const char* name;
    int         tile_count;
    int         tile_width;
    int         tile_height;
    int         margin;
    int         spacing;
    int         columns;
    s_tmx_image *image;

} TmxTileSet;

typedef struct s_tmx_image
{
    const char* format;
    const char* source;
    int         width;
    int         height;
} TmxImage;


typedef struct s_tmx_layer
{
    int                     id;
    const char*             name;
    int                     x;
    int                     y;
    int                     width;
    int                     height;
    float                   opacity;
    bool                    visible;
    int                     offset_x;
    int                     offset_y;
    s_tmx_data              *data;
} TmxLayer;

typedef struct s_tmx_data
{
    const char* encoding;
    const char* compression;
    const char* content;
} TmxData;



#endif // TILEMAP_DEFINE_H
