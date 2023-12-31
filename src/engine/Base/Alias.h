#ifndef ALIAS_H
#define ALIAS_H

#include <stdint.h>
#include <bitset>

#include <CommonDefine.h>

BEGIN_NAMESPACE(engine)

using EntityID      = uint32_t;
using ComponentID   = uint32_t;

const EntityID MIN_ENTITY_COUNT     = 0;
const EntityID MIN_ENTITY_ID        = 0;
const EntityID MAX_ENTITY_ID        = 50;

const ComponentID MIN_COMPONENT_COUNT       = 0;
const ComponentID MIN_COMPONENT_ID          = 0;
const ComponentID MAX_COMPONENT_ID          = 32; // maximum components per entity

using ComponentSet = std::bitset<MAX_COMPONENT_ID>; // 00000000000000000000000000000000


using _TextureID = const char*;
using _TextureSource = const char*;

using _FrameWidth = int;
using _FrameHeight = int;

using _FrameWidthF = float;
using _FrameHeightF = float;

using _FrameRow = int;
using _FrameCol = int;

using _Scale    = float;

using _TileWidth = int;
using _TileHeight = int;

using _TileWidthF = float;
using _TileHeightF = float;

using TileRow = int;
using TileCol = int;

using _Title = const char*;
using _Width = uint32_t;
using _Height = uint32_t;
using _Angle = float;

END_NAMESPACE

#endif // ALIAS_H
