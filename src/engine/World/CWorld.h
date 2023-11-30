#ifndef CWORLD_H
#define CWORLD_H

#include "CommonDefine.h"
#include "vector2D.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class AScene;
class CWorld
{
private:
    explicit CWorld();
    ~CWorld();
    static CWorld *s_instance;

    Vector2DF m_gravity;
    std::vector<CEntity*> m_entities;
    std::vector<AScene*>  m_scenes;

public:
    static CWorld *instance();
    CWorld *registerEntity(CEntity*);
    CWorld *registerScene(AScene*);


    void init();
    void update(float);
    void render();
};
END_NAMESPACE

#endif // CWORLD_H
