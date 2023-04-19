#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct CameraComponent: public ComponentBase<CameraComponent>
{
    CameraComponent(bool focus = 0): inFocus(focus){}
    bool inFocus;
};
}

#endif // CAMERACOMPONENT_H
