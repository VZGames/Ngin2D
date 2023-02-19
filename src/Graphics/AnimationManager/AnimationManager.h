#ifndef AnimationManager_H
#define AnimationManager_H

#include <SDL2/SDL.h>
#include <vector>
#include "../../Objects/IObject.h"

class AnimationManager: public IObject
{


    // IObject interface
public:
    virtual void draw() override;
    virtual void update() override;
    virtual void clean() override;

public:
    static AnimationManager *instance();
    void createOne(const char* textureID, int frameX, int frameY, int frameCount, int frameDuration, SDL_RendererFlip p_flip);

private:
    AnimationManager();
    static AnimationManager *s_instance;


};

#endif // AnimationManager_H
