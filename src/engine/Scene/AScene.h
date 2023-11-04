#ifndef ASCENE_H
#define ASCENE_H

#include "CommonDefine.h"
#include "CEntity.h"

BEGIN_NAMESPACE(GameNgin)
class AScene
{
public:
    friend class CSceneManager;
    const char *id() const;

private:
    const char* m_id;
};
END_NAMESPACE

#endif // ASCENE_H
