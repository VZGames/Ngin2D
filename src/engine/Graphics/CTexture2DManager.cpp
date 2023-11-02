#include "CTexture2DManager.h"

BEGIN_NAMESPACE(GameNgin)
CTexture2DManager::CTexture2DManager()
{

}

void CTexture2DManager::drawTile(TextureID id, Point2DI pos, TileWidth w, TileHeight h, TileRow r, TileCol c)
{
    UNUSED(id);
    UNUSED(pos);
    UNUSED(w);
    UNUSED(h);
    UNUSED(r);
    UNUSED(c);
}

void CTexture2DManager::drawFrame(TextureID id, Point2DI pos, FrameWidth w, FrameHeight h, FrameRow r, FrameCol c)
{
    UNUSED(id);
    UNUSED(pos);
    UNUSED(w);
    UNUSED(h);
    UNUSED(r);
    UNUSED(c);
}

bool CTexture2DManager::loadTexture(TextureID id, TextureSource source)
{
    UNUSED(id);
    UNUSED(source);
}
END_NAMESPACE


