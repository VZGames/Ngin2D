#include "CWorld.h"

BEGIN_NAMESPACE(GameNgin)
CWorld* CWorld::s_instance = nullptr;
CWorld::CWorld()
{

}

CWorld* CWorld::instance()
{
    return s_instance = (s_instance == nullptr)? new CWorld():s_instance;
}

void CWorld::registerEntity(CEntity*entity)
{
    
}

void CWorld::registerScene(AScene*scene)
{
    
}
END_NAMESPACE
