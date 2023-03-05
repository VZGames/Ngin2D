#ifndef PLAYER_H
#define PLAYER_H

#include "../../IEntity.h"
#include "../../Entity.h"

using namespace ngin2D;
class Player: public IEntity
{
public:
    static Player *instance();

    // IEntity interface
public:
    virtual void handleKeyEvent() override;
    virtual void handleMouseEvent() override;

private:
    Player();
    static Player *s_instance;
    Entity *entity;
};

#endif // PLAYER_H
