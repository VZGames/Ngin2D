#ifndef COMMONENUMS_Script_H
#define COMMONENUMS_Script_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(script)
enum E_MOVE_DIRECTION: char
{
    MOVE_NONE,
    MOVE_LEFT,
    MOVE_UP,
    MOVE_RIGHT,
    MOVE_DOWN
};

enum E_CTRL_SLOTS
{
    CTRL_SLOTS_0,
    CTRL_SLOTS_1,
    CTRL_SLOTS_2,
    CTRL_SLOTS_3,
    CTRL_SLOTS_4,
    CTRL_SLOTS_5,
    CTRL_SLOTS_6,
    CTRL_SLOTS_7,
    CTRL_SLOTS_8,
    CTRL_SLOTS_9,
    CTRL_SLOTS_10,
};
END_NAMESPACE

#endif // COMMONENUMS_Script_H
