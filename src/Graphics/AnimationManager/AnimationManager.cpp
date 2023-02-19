#include "AnimationManager.h"
#include "../TextureManager/TextureManager.h"


AnimationManager *AnimationManager::s_instance = nullptr;

AnimationManager::AnimationManager()
{
}

AnimationManager *AnimationManager::instance()
{
    return s_instance = (s_instance == nullptr)? new AnimationManager(): s_instance;
}

void AnimationManager::createOne(const char *textureID, int frameX, int frameY, int frameCount, int frameDuration, SDL_RendererFlip p_flip)
{

}

void AnimationManager::draw()
{
    
}

void AnimationManager::update()
{
    
}

void AnimationManager::clean()
{
    
}

