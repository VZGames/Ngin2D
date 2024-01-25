#ifndef TMXFORMAT_H
#define TMXFORMAT_H

#include <stdint.h>
#include <unordered_map>
#include <optional>

struct s_tmx_map;
struct s_tmx_image;
struct s_tmx_data;
struct s_tmx_layer;
struct s_tmx_tileset;
struct s_tmx_tile;
struct s_tmx_objectgroup;
struct s_tmx_shape;

typedef struct s_tmx_map
{
    const char*             version{""};
    const char*             tiled_version{""};
    const char*             orientation{""};
    const char*             render_order{""};
    int                     width{0};
    int                     height{0};
    int                     tile_width{0};
    int                     tile_height{0};
    int                     next_layer_id{0};
    int                     next_object_id{0};
    bool                    infinite{false};
    s_tmx_tileset           *tilesets{nullptr};
    s_tmx_layer             *layers{nullptr};
    s_tmx_objectgroup       *objectgroups{nullptr};

} TmxMap;

typedef struct s_tmx_tile
{
    int id{0};
    const char* type{""};
    int x{0};
    int y{0};
    int width{0};
    int height{0};
} TmxTile;

typedef struct s_tmx_tileset
{
    int         first_global_id{0};
    const char* name{""};
    int         tile_count{0};
    int         tile_width{0};
    int         tile_height{0};
    int         margin{0};
    int         spacing{0};
    int         columns{0};
    int         rows{0};
    s_tmx_image *image{nullptr};
    s_tmx_tile  *tiles{nullptr};

} TmxTileSet;

typedef struct s_tmx_image
{
    const char* format{""};
    const char* source{""};
    int         width{0};
    int         height{0};
} TmxImage;


typedef struct s_tmx_layer
{
    int                     id{0};
    const char*             name{""};
    int                     x{0};
    int                     y{0};
    int                     width{0};
    int                     height{0};
    float                   opacity{1};
    bool                    visible{true};
    int                     offset_x{0};
    int                     offset_y{0};
    s_tmx_data              *data{nullptr};
} TmxLayer;

typedef struct s_tmx_data
{
    const char* encoding{""};
    const char* compression{""};
    const char* content{""};
} TmxData;

typedef struct s_tmx_object
{
    int id;
    int x, y;
    int width, height;
    s_tmx_shape* shape;
} TmxObject;

typedef struct s_tmx_objectgroup
{
    int id;
    int x, y;
    int width, height;
    const char *name;
    TmxObject  *object{nullptr};
} TmxObjectGroup;

struct s_tmx_shape
{
    int id;
    float x,y;
    const char* name;
};

typedef struct s_tmx_ellipse: public s_tmx_shape
{
    float width, height;
} TmxEllipse;

typedef struct s_tmx_polygon: public s_tmx_shape
{
    int num_of_vertex;
    float *vertices;
} TmxPolygon;

typedef struct s_tmx_rectangle: public s_tmx_shape
{
} TmxRectangle;

typedef struct s_tmx_point: public s_tmx_shape
{
} TmxPoint;

#endif // TMXFORMAT_H
