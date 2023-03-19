#ifndef SPAWNSYSTEM_H
#define SPAWNSYSTEM_H


#include "SDL2/SDL.h"
#include "../ISystem.h"

namespace ngin2D {
class SpawnSystem: public ISystem
{
public:
    SpawnSystem();

    // ISystem interface
public:
    virtual void update(float dt) override;


private:
    SDL_Rect camera;
};
}
#endif // SPAWNSYSTEM_H
