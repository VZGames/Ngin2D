#include "TextureManager.h"
#include "../../Game/Game.h"

TextureManager *TextureManager::s_instance = nullptr;

TextureManager::TextureManager()
{
}

TextureManager *TextureManager::instance()
{
    return s_instance = (s_instance == nullptr)? new TextureManager(): s_instance;
}

SDL_Texture *TextureManager::textureById(const char*  textureID)
{
    return textureDict[textureID];
}

bool TextureManager::loadTexture(const char*  textureID, const char *filePath)
{
    printf("TextureID: %s, Texture Path: %s \n", textureID, filePath);

    SDL_Texture *texture = NULL;
    SDL_Surface *surface = IMG_Load(filePath);
    if (surface) {
        texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), surface);
        SDL_FreeSurface(surface);
    }

    textureDict[textureID] = texture;
    return 1;
}

void TextureManager::draw(const char*  textureID, Point2D pos, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect destRect = {pos.getX(), pos.getY(), width, height};
    SDL_RenderCopy(Game::instance()->getRenderer(), textureDict[textureID], &srcRect, &destRect);
}

void TextureManager::drawTile(const char*  textureID, int tileWidth, int tileHeight, Point2D pos, int row, int col, SDL_RendererFlip flip)
{
    int frameX = tileWidth * col;
    int frameY = tileHeight * row;

    SDL_Rect srcRect = {frameX, frameY, tileWidth, tileHeight};
    SDL_Rect destRect = {pos.getX(), pos.getY(), tileWidth, tileHeight};
    SDL_RenderCopyEx(Game::instance()->getRenderer(), textureDict[textureID], &srcRect, &destRect, 0, NULL, flip);
}

void TextureManager::drawFrame(const char*  textureID, Point2D pos, int width, int height, int row, int col, SDL_RendererFlip flip, double angle)
{
    int frameX = width * col;
    int frameY = height * row;

    SDL_Rect srcRect = {frameX, frameY, width, height};
    SDL_Rect destRect = {pos.getX(), pos.getY(), width, height};
    SDL_RenderCopyEx(Game::instance()->getRenderer(), textureDict[textureID], &srcRect, &destRect, 0, NULL, flip);
}

void TextureManager::drop(const char*  textureID)
{
    SDL_DestroyTexture(textureDict[textureID]);
    textureDict.erase(textureID);
}

void TextureManager::clean()
{
    for(auto &texture: textureDict)
    {
        SDL_DestroyTexture(texture.second);
    }
    textureDict.clear();
    printf("Textures cleaned\n");
}


