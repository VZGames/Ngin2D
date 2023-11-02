#ifndef CWORLD_H
#define CWORLD_H

#include "CommonDefine.h"
BEGIN_NAMESPACE(GameNgin)
class CEntity;
class AScene;
class CWorld
{
private:
    CWorld();
    static CWorld *s_instance;
public:
    static CWorld *instance();
    
    void registerEntity(CEntity*);
    void registerScene(AScene*);
};
END_NAMESPACE

#endif // CWORLD_H
