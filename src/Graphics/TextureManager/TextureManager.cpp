#include "TextureManager.h"
#include "../../Engine/Engine.h"

TextureManager *TextureManager::s_instance = nullptr;

TextureManager *TextureManager::instance()
{
    return s_instance = (s_instance == nullptr)? new TextureManager(): s_instance;
}

void TextureManager::LoadTexture(const char *textureID, const char *filePath)
{
    printf("TextureID: %s, Texture Path: %s \n", textureID, filePath);
    SDL_Surface *surface = SDL_LoadBMP(filePath);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Engine::s_renderer, surface);

    //    m_TextureDict[textureID] = tex;
    SDL_FreeSurface(surface);

    surface = nullptr;
}

void TextureManager::Draw(char *textureID, Vector2I pos, int width, int height, SDL_RendererFlip flip)
{
//    SDL_Rect srcRect = {0, 0, width, height};
//    SDL_Rect dstRect = {pos.m_X, pos.m_Y, width, height};
//    SDL_RenderCopyEx(Engine::s_renderer, textureDict[textureID], &srcRect, &dstRect, 0, NULL, p_Flip);
}

void TextureManager::DrawTile(const char *tileID, int tileSize, Vector2I pos, int row, int frame, SDL_RendererFlip flip)
{

}

void TextureManager::DrawFrame(const char *textureID, Vector2I pos, int width, int height, int row, int frame, SDL_RendererFlip flip, double angle)
{

}

void TextureManager::Drop(const char *textureID)
{

}

void TextureManager::Clean()
{

}

TextureManager::TextureManager()
{

}

