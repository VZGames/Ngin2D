#ifndef SPAWNSYSTEM_H
#define SPAWNSYSTEM_H


#include "SDL2/SDL.h"
#include "ECS/Systems/ISystem.h"

namespace ngin2D {
class SpawnSystem: public ISystem
{
public:
    SpawnSystem();

    // ISystem interface
public:
    virtual void init() override;
    virtual void update(float dt) override;
    virtual void render() override;


private:
    SDL_Rect camera;


};
}
#endif // SPAWNSYSTEM_H
