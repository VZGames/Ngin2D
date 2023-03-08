#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include "ComponentBase.h"

namespace ngin2D {
struct CameraComponent: public ComponentBase<CameraComponent>
{
    CameraComponent(Size size): size(size){}
    Size size;
    Point2DI position;
    int zoom = 5;
};
}

#endif // CAMERACOMPONENT_H
