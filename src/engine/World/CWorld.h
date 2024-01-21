#ifndef CWORLD_H
#define CWORLD_H

#include <CommonDefine.h>
#include "vector2D.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class AScene;
class CWorld
{
private:
    explicit CWorld();
    static CWorld *s_instance;

    Vector2D<float> m_gravity;
    std::vector<CEntity*> m_entities;
    std::vector<AScene*>  m_scenes;

public:
    ~CWorld();
    static CWorld *instance();
    CWorld *registerEntity(CEntity*);
    void unRegisterEntity(CEntity*);
    CWorld *registerScene(AScene*);
    void unRegisterScene(AScene*);


    void init();
    void update(float);
    void render();
};
END_NAMESPACE

#endif // CWORLD_H
