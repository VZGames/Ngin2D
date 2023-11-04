#ifndef ALIAS_H
#define ALIAS_H

#include <stdint.h>
#include <bitset>

#include "CommonDefine.h"

BEGIN_NAMESPACE(Ngin)

using EntityID      = uint32_t;
using ComponentID   = uint32_t;

const EntityID MIN_ENTITY_COUNT     = 0;
const EntityID MIN_ENTITY_ID        = 0;
const EntityID MAX_ENTITY_ID        = 50;

const ComponentID MIN_COMPONENT_COUNT       = 0;
const ComponentID MIN_COMPONENT_ID          = 0;
const ComponentID MAX_COMPONENT_ID          = 32; // maximum components per entity

using ComponentSet = std::bitset<MAX_COMPONENT_ID>; // 00000000000000000000000000000000


using TextureID = const char*;
using TextureSource = const char*;

using FrameWidth = int;
using FrameHeight = int;

using FrameRow = int;
using FrameCol = int;

using TileWidth = int;
using TileHeight = int;

using TileRow = int;
using TileCol = int;

using Title = const char*;
using Width = uint32_t;
using Height = uint32_t;
using Angle = float;

END_NAMESPACE

#endif // ALIAS_H
