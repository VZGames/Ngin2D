#ifndef PLAYER_H
#define PLAYER_H

#include "ECS/Entity/IEntity.h"

using namespace ngin2D;
class Player: public IEntity
{
public:
    static Player *instance();

    EntityID getID() const;

    // IEntity interface
public:
    virtual void followTarget(Entity *target) override;
    virtual void handleKeyEvent() override;
    virtual void handleMouseEvent() override;

private:
    Player();
    ~Player();
    static Player *s_instance;
};

#endif // PLAYER_H
