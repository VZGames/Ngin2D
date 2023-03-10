#ifndef MOUSEAREACOMPONENT_H
#define MOUSEAREACOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct MouseAreaComponent: public ComponentBase<MouseAreaComponent>
{
    MouseAreaComponent();
    Point2DI position;
};
}

#endif // MOUSEAREACOMPONENT_H
