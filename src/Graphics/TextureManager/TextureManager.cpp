#include "TextureManager.h"
#include "../../Engine/Engine.h"

TextureManager *TextureManager::s_instance = nullptr;

TextureManager *TextureManager::instance()
{
    return s_instance = (s_instance == nullptr)? new TextureManager(): s_instance;
}

SDL_Texture *TextureManager::texture_by_id(const char *textureID)
{
    return textureDict[textureID];
}

TextureManager::TextureManager()
{
}

bool TextureManager::load_texture(const char *textureID, const char *filePath)
{
    printf("TextureID: %s, Texture Path: %s \n", textureID, filePath);

    SDL_Surface *suff = IMG_Load(filePath);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Engine::s_renderer, suff);

    if(tex == nullptr)
    {
        printf("Failed to load_texture texture. Error: %s", SDL_GetError());
        return 0;
    }

    SDL_FreeSurface(suff);
    suff = nullptr;
    textureDict[textureID] = tex;
    return 1;
}

void TextureManager::draw(const char *textureID, Point2D pos, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect destRect = {pos.getX(), pos.getY(), width, height};
    SDL_RenderCopy(Engine::s_renderer, textureDict[textureID], NULL, &destRect);
}

void TextureManager::draw_tile(const char *textureID, int tileSize, Point2D pos, int row, int col, SDL_RendererFlip flip)
{
    int frameX = tileSize * col;
    int frameY = tileSize * row;

    SDL_Rect srcRect = {frameX, frameY, tileSize, tileSize};
    SDL_Rect destRect = {pos.getX(), pos.getY(), tileSize, tileSize};
    SDL_RenderCopyEx(Engine::s_renderer, textureDict[textureID], &srcRect, &destRect, 0, NULL, flip);
}

void TextureManager::draw_frame(const char *textureID, Point2D pos, int width, int height, int row, int col, SDL_RendererFlip flip, double angle)
{
    int frameX = width * col;
    int frameY = height * (row - 1);

    SDL_Rect srcRect = {frameX, frameY, width, height};
    SDL_Rect destRect = {pos.getX(), pos.getY(), width, height};
    SDL_RenderCopyEx(Engine::s_renderer, textureDict[textureID], &srcRect, &destRect, 0, NULL, flip);
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
    textureDict.clear();
    printf("Texture cleaned\n");
}


