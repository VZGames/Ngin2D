#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct CameraComponent: public ComponentBase<CameraComponent>
{
    CameraComponent(Size size): size(size){}
    Size size;
    Point2D position;
};
}

#endif // CAMERACOMPONENT_H
