#ifndef GAMEMAPS_H
#define GAMEMAPS_H

#include "../Objects/IObject.h"

class GameMaps: public IObject
{
public:
    GameMaps();


    // IObject interface
public:
    virtual void draw() override;
    virtual void update() override;
    virtual void clean() override;
};

#endif // GAMEMAPS_H
