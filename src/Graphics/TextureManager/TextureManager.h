#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../../Math/Vector2D.h"

class TextureManager
{

public:
    static TextureManager *instance();

    void LoadTexture(const char *textureID, const char *filePath);
    void Draw(char *textureID, Vector2I pos, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void DrawTile(const char *tileID, int tileSize, Vector2I pos, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void DrawFrame(const char *textureID, Vector2I pos, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE, double p_Angle = 0);
    void Drop(const char *textureID);
    void Clean();

private:
    TextureManager();
    static TextureManager *s_instance;
};

#endif // TEXTUREMANAGER_H
