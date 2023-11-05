#ifndef CWORLD_H
#define CWORLD_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(Ngin)
class CEntity;
class AScene;
class CWorld
{
private:
    explicit CWorld();
    static CWorld *s_instance;

    static std::vector<CEntity*> s_entities;
    static std::vector<AScene*>  s_scenes;

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
