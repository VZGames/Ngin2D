#ifndef CPLAYER_H
#define CPLAYER_H

#include "CommonDefine.h"
#include "Entity/CEntity.h"
#include "Common/enums.h"

BEGIN_NAMESPACE(GameScript)
class CPlayer: public GameNgin::CEntity
{
public:
    CPlayer();

    void idle();
    void jump();
    void walk(MOVE_DIRECTION);
    void attach(CTRL_SLOTS);
};
END_NAMESPACE

#endif // CPLAYER_H
