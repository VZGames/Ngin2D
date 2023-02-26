#ifndef ALIAS_H
#define ALIAS_H

#include <stdint.h>
#include <bitset>

using EntityID = uint32_t;
using ComponentID = uint32_t;

// Used to define the size of arrays later on
const EntityID MAX_ENTITIES = 50;
const ComponentID MAX_COMPONENTS = 32;

using Signature = std::bitset<MAX_COMPONENTS>();

#endif // ALIAS_H
