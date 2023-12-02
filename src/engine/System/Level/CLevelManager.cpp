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

void CLevelManager::createLevel(const char *id, ALevel *level)
{
    m_levels[id] = level;
}

void CLevelManager::loadLevel(const char *id)
{
    // Load map data, entities, etc.
    m_current_level_id = id;
}

void CLevelManager::unLoadLevel()
{
    // Unload map data, entities, etc.
}

ALevel *CLevelManager::currentLevel() const
{
    return m_levels.at(m_current_level_id);
}

END_NAMESPACE






