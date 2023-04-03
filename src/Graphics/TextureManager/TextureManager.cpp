#include "TextureManager.h"
#include "Game/Game.h"
#include <cassert>
#include "Scene/Camera/Camera.h"


namespace ngin2D {
TextureManager *TextureManager::s_instance = nullptr;

TextureManager::TextureManager()
{
}

TextureManager *TextureManager::instance()
{
    return s_instance = (s_instance == nullptr)? new TextureManager(): s_instance;
}

SDL_Texture *TextureManager::textureById(const char * textureID)
{
    return textureDict[textureID];
}

bool TextureManager::loadTexture(const char * textureID, const char *filePath)
{
    if(textureDict.find(textureID) != textureDict.end())
    {
        return 1;
    }
    printf("TextureID: %s, Texture Path: %s \n", textureID, filePath);

    SDL_Texture *texture = NULL;
    SDL_Surface *surface = IMG_Load(filePath);
    if (!surface) {
        return 0;
    }
    texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), surface);
    SDL_FreeSurface(surface);

    textureDict[textureID] = texture;
    return 1;
}

void TextureManager::draw(const char * textureID, Point2DI pos, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect destRect = {pos.getX(), pos.getY(), width, height};
    SDL_RenderCopy(Game::instance()->getRenderer(), textureDict[textureID], &srcRect, &destRect);
}

void TextureManager::drawTile(const char * textureID, int tileWidth, int tileHeight, Point2DI pos, int row, int col, SDL_RendererFlip flip)
{
    int frameX = tileWidth  *col;
    int frameY = tileHeight  *row;

    auto cameraPos = Camera::instance()->position();

    SDL_Rect srcRect = {frameX, frameY, tileWidth, tileHeight};
    SDL_Rect destRect = {
        (int)(pos.getX() - cameraPos.getX()),
        (int)(pos.getY() - cameraPos.getY()),
        tileWidth,
        tileHeight
    };

    SDL_RenderCopyEx(Game::instance()->getRenderer(), textureDict[textureID], &srcRect, &destRect, 0, NULL, flip);
}

void TextureManager::drawFrame(const char * textureID, Point2DI pos, int width, int height, int row, int col, SDL_RendererFlip flip, float angle)
{
    int frameX = width * col;
    int frameY = height * row;

    SDL_Rect srcRect = {frameX, frameY, width, height};
    SDL_Rect destRect = {
        pos.getX(),
        pos.getY(),
        width,
        height
    };

    SDL_Rect box = {pos.getX(),  pos.getY(), width, height};
    SDL_RenderDrawRect(Game::instance()->getRenderer(), &box);

    SDL_RenderCopyEx(Game::instance()->getRenderer(), textureDict[textureID], &srcRect, &destRect, 0, NULL, flip);
}


void TextureManager::drawEllipse(Point2DF I, float radiusX, float radiusY)
{
    float centerX = I.getX();
    float centerY = I.getY();
    float step = 0.01f;

    for (auto angle = 0.0f; angle < PI * 2.0f; angle += step) {
        float x = centerX + std::cos(angle) * radiusX;
        float y = centerY + std::sin(angle) * radiusY;
        SDL_RenderDrawPointF(Game::instance()->getRenderer(), x, y);
    }
}

void TextureManager::drawRectangle(Point2DF pos, float width, float height)
{
    SDL_FRect rect = {pos.getX(),  pos.getY(), width, height};
    SDL_RenderDrawRectF(Game::instance()->getRenderer(), &rect);
}

void TextureManager::drawPolygon(Point2DF pos, std::vector<Point2DF> points)
{
    SDL_FPoint _points[points.size()];
    for (int i = 0; i < points.size(); i++) {
        auto cameraPos = Camera::instance()->position();
        _points[i] = {pos.getX() + points[i].getX() - cameraPos.getX(),
                      pos.getY() + points[i].getY() - cameraPos.getY()};
    }

    int numPoints = sizeof(_points) / sizeof(SDL_FPoint);
    SDL_RenderDrawLinesF(Game::instance()->getRenderer(), _points, numPoints);
}

void TextureManager::drop(const char * textureID)
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
}
