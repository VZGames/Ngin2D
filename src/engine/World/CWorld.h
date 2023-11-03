#ifndef CWORLD_H
#define CWORLD_H

#include "CommonDefine.h"
BEGIN_NAMESPACE(GameNgin)
class CEntity;
class AScene;
class CWorld
{
private:
    explicit CWorld();
    static CWorld *s_instance;

    std::vector<CEntity*> m_entities;
    std::vector<AScene*>  m_scenes;

public:
    static CWorld *instance();
    
    void registerEntities(std::vector<CEntity*>&);
    void registerScenes(std::vector<AScene*>&);


    void init();
    void update(float);
    void render();
};
END_NAMESPACE

#endif // CWORLD_H
