#include "Camera.h"
#include "GameMaps/MapParser.h"

namespace ngin2D {
Camera *Camera::s_instance = nullptr;
Camera *Camera::instance()
{
    return s_instance = (s_instance == nullptr)? new Camera():s_instance;
}

Camera::Camera()
{
    m_viewport = {0, 0, 50, 50};
}

const SDL_Rect &Camera::viewport() const
{
    return m_viewport;
}

void Camera::update(float dt)
{
    if(ptr_entity != nullptr)
    {
        auto position = ptr_entity->getComponent<PositionComponent>();
        m_viewport.x = position->x - m_viewport.w/2;
        m_viewport.y = position->y - m_viewport.h/2;


        int mapWidth = MapParser::instance()->getMapSize().width;
        int mapHeight = MapParser::instance()->getMapSize().height;

        if(m_viewport.x < 0)
        {
            m_viewport.x = 0;
        }

        if(m_viewport.y < 0)
        {
            m_viewport.y = 0;
        }

        if(m_viewport.x > (mapWidth - m_viewport.w))
        {
            m_viewport.x = (mapWidth - m_viewport.w);
        }

        if(m_viewport.y < (mapHeight - m_viewport.h))
        {
            m_viewport.y = (mapHeight - m_viewport.h);
        }
    }
}

void Camera::moveTo()
{
    
}

void Camera::setTarget(EntityID id)
{
    ptr_entity = EntityManager::instance()->getEntityByID(id);
}

}
