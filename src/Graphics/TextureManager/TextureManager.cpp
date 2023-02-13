#include "TextureManager.h"
#include "../../Engine/Engine.h"

TextureManager *TextureManager::s_instance = nullptr;

TextureManager *TextureManager::instance()
{
    return s_instance = (s_instance == nullptr)? new TextureManager(): s_instance;
}

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
    clean();
}

bool TextureManager::load(const char *textureID, const char *filePath)
{
    printf("TextureID: %s, Texture Path: %s \n", textureID, filePath);

    SDL_Surface *surface = SDL_LoadBMP(filePath);
    if (surface == nullptr) {
        return 0;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(Engine::s_renderer, surface);
    if (texture == nullptr) {
        return 0;
    }

    textureDict[textureID] = texture;
    SDL_FreeSurface(surface);

    surface = nullptr;
    return 1;
}

void TextureManager::draw(const char *textureID, Vector2I pos, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect dstRect = {pos.x, pos.y, width, height};
    SDL_RenderCopyEx(Engine::s_renderer, textureDict[textureID], &srcRect, &dstRect, 0, NULL, flip);
}

void TextureManager::draw_tile(const char *tileID, int tileSize, Vector2I pos, int row, int col, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {pos.x, pos.y, tileSize, tileSize};
    SDL_Rect destRect = {tileSize * col, tileSize * row, tileSize, tileSize};
    SDL_RenderCopyEx(Engine::s_renderer, textureDict[tileID], &srcRect, &destRect, 0, NULL, flip);
}

void TextureManager::drawFrame(const char *textureID, Vector2I pos, int width, int height, int row, int col, SDL_RendererFlip flip, double angle)
{
    int frameX = width * col;
    int frameY = height * row;

    SDL_Rect srcRect = {frameX, frameY, width, height};
    SDL_Rect dstRect = {pos.x, pos.y, width, height};
    SDL_RenderCopyEx(Engine::s_renderer, textureDict[textureID], &srcRect, &dstRect, 0, NULL, flip);
}

void TextureManager::drop(const char *textureID)
{
    SDL_DestroyTexture(textureDict[textureID]);
    textureDict.erase(textureID);
}

void TextureManager::clean()
{
    for(auto texture: textureDict)
    {
        SDL_DestroyTexture(texture.second);
    }
}


