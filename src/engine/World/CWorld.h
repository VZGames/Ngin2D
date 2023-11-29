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
    static std::vector<CEntity*> s_entities;
    static std::vector<AScene*>  s_scenes;

public:
    static CWorld *instance();
    static void forEachEntities(std::function<void(CEntity*)>);
    static void forEachScenes(std::function<void(AScene*)>);

    CWorld *registerEntities(std::vector<CEntity*>);
    CWorld *registerScene(AScene*);


    void init();
    void update(float);
    void render();
};
END_NAMESPACE

#endif // CWORLD_H
