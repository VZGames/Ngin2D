#include "CEntityManager.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(engine)
CEntityManager *CEntityManager::s_instance = nullptr;
CEntityManager::CEntityManager()
{
    for(EntityID id = MIN_ENTITY_ID; id < MAX_ENTITY_ID; id++)
    {
        m_available_ids.push(id);
    }
}

CEntityManager *CEntityManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CEntityManager():s_instance;
}

bool CEntityManager::createEntity(CEntity *newEntity)
{
    assert(m_entity_count <= MAX_ENTITY_ID && "The maximum number of entity creations has been reached");

    EntityID id = m_available_ids.front();
    newEntity->setId(id);

    m_entities.push_back(newEntity);
    m_entity_count++;

    m_available_ids.pop();

    MORGAN_DEBUG("Created Entity has ID %d", id)
    return true;
}

bool CEntityManager::destroyEntity(CEntity *oldEntity)
{
    std::vector<CEntity*>::iterator it = m_entities.begin();
    while(it != m_entities.end())
    {
        if((*it)->id() == oldEntity->id())
        {
            m_entities.erase(it);
            safeRelease((*it));
            return true;
        }
        ++it;
    }
    return false;
}
std::vector<CEntity *> CEntityManager::entities() const
{
    return m_entities;
}
END_NAMESPACE




