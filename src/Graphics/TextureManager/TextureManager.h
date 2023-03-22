#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math/math2D.h"

namespace ngin2D {
class TextureManager
{

public:
    static TextureManager *instance();

    SDL_Texture *textureById(const char * textureID);
    bool loadTexture(const char * textureID, const char *filePath);
    void draw(const char * textureID, Point2DI pos, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawTile(const char * textureID,int tileWidth, int tileHeight, Point2DI pos, int row, int col, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(const char * textureID, Point2DI pos, int width, int height, int row, int col, SDL_RendererFlip flip = SDL_FLIP_NONE, double p_Angle = 0);
    void drop(const char * textureID);
    void clean();

private:
    TextureManager();
    static TextureManager *s_instance;

    std::map<const char*, SDL_Texture*> textureDict;
};
}


#endif // TEXTUREMANAGER_H
