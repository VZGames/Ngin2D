#include "CLevelManager.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(engine)
CLevelManager* CLevelManager::s_instance = nullptr;
CLevelManager::CLevelManager()
{

}


CLevelManager* CLevelManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CLevelManager(): s_instance;
}

void CLevelManager::loadLevel(const char *id)
{
    UNUSED(id)
}

void CLevelManager::update(float dt)
{
    UNUSED(dt)
}
END_NAMESPACE


