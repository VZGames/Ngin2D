#ifndef GAMEMAPS_H
#define GAMEMAPS_H

#include "../Objects/IObject.h"

class GameMaps: public IObject
{
    // IObject interface
public:
    static GameMaps *instance();
    virtual void draw() override;
    virtual void update() override;
    virtual void clean() override;

private:
    GameMaps();
    static GameMaps *s_instance;

};

#endif // GAMEMAPS_H
