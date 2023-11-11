#ifndef ATEXTUREMANAGER_H
#define ATEXTUREMANAGER_H

#include "CommonDefine.h"
#include "Alias.h"

BEGIN_NAMESPACE(engine)
class ATextureManager
{
protected:
    std::mutex  m_mutex;
public:
    virtual bool loadTexture(TextureID, TextureSource) = 0;
};
END_NAMESPACE

#endif // ATEXTUREMANAGER_H
