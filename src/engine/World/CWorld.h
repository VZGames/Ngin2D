#ifndef CWORLD_H
#define CWORLD_H

#include "CommonDefine.h"
#include "ContactListener/CCustomContactListener.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class AScene;
class CWorld: public b2World
{
private:
    explicit CWorld();
    ~CWorld();
    static CWorld *s_instance;

    static std::vector<CEntity*> s_entities;
    static std::vector<AScene*>  s_scenes;
    float m_timeStep = 1.0f / 60.0f;
    int32 m_velocity_iterations = 10;
    int32 m_position_iterations = 4;
    b2Vec2 m_gravity;

    // contact listener
    CCustomContactListener  m_my_contact;

public:
    static CWorld *instance();
    static void forEachEntities(std::function<void(CEntity*)>);
    static void forEachScenes(std::function<void(AScene*)>);

    CWorld * registerEntities(std::vector<CEntity*>&);
    CWorld * registerScenes(std::vector<AScene*>&);


    void init();
    void update(float);
    void render();
};
END_NAMESPACE

#endif // CWORLD_H
