#include "Camera.h"

namespace ngin2D {
Camera::Camera()
{


}

Camera::~Camera()
{

}

const ViewPort &Camera::getViewport() const
{
    return viewport;
}

void Camera::setViewport(const ViewPort &newViewport)
{
    viewport = newViewport;
}
}
