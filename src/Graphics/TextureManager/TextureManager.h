#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../../Math/math2D.h"

class TextureManager
{

public:
    static TextureManager *instance();
    ~TextureManager();

    bool load(const char *textureID, const char *filePath);
    void draw(const char *textureID, Point2D pos, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void draw_tile(const char *tileID, int tileSize, Point2D pos, int row, int col, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void draw_frame(const char *textureID, Point2D pos, int width, int height, int row, int col, SDL_RendererFlip flip = SDL_FLIP_NONE, double p_Angle = 0);
    void drop(const char *textureID);
    void clean();

private:
    TextureManager();
    static TextureManager *s_instance;

    std::map<const char *, SDL_Texture*> textureDict;

};

#endif // TEXTUREMANAGER_H
