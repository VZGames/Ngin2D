#ifndef TMXFORMAT_H
#define TMXFORMAT_H

#include <stdint.h>

struct s_tmx_map;
struct s_tmx_image;
struct s_tmx_data;
struct s_tmx_layer;
struct s_tmx_tileset;
struct s_tmx_tile;

typedef struct s_tmx_map
{
    const char*             version;
    const char*             tiled_version;
    const char*             orientation;
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

typedef struct s_tmx_tile
{
    int id;
    const char* type;
    int x;
    int y;
    int width;
    int height;
} TmxTile;

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
    int         rows;
    s_tmx_image *image;
    s_tmx_tile  *tiles;

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



#endif // TMXFORMAT_H
