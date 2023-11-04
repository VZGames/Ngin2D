#ifndef ASCENE_H
#define ASCENE_H

#include "CommonDefine.h"
#include "CEntity.h"

BEGIN_NAMESPACE(GameNgin)
class AScene
{
public:
    friend class CSceneManager;

    virtual void init();
    virtual void update(std::vector<GameNgin::CEntity*> &entities, float dt);
    virtual void render();

    const char *id() const;

private:
    const char* m_id;
};
END_NAMESPACE

#endif // ASCENE_H
