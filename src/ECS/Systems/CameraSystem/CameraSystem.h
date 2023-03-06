#ifndef CAMERASYSTEM_H
#define CAMERASYSTEM_H

#include "SDL2/SDL.h"
#include "../ISystem.h"

namespace ngin2D {
class CameraSystem: public ISystem
{
public:
    CameraSystem();

    // ISystem interface
public:
    virtual void update(float dt) override;


private:
    SDL_Rect camera;
};
}

#endif // CAMERASYSTEM_H
