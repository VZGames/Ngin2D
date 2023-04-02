#include "Camera.h"
#include "Math/math2D.h"
#include "GameMaps/MapParser.h"

namespace ngin2D {
Camera *Camera::s_instance = nullptr;
Camera *Camera::instance()
{
    return s_instance = (s_instance == nullptr)? new Camera():s_instance;
}

Camera::Camera()
{
    m_viewPort = {
        0.0f,
        0.0f,
        std::round((float)g_width/ZOOM_FACTOR),
        std::round((float)g_height/ZOOM_FACTOR)
    };
}

Point2DF Camera::position() const
{
    return m_position;
}

const SDL_FRect &Camera::viewport() const
{
    return m_viewPort;
}

void Camera::update(float dt)
{
    if(ptr_entity != nullptr)
    {
        auto sprite = ptr_entity->getComponent<SpriteComponent>();
        auto pos    = ptr_entity->getComponent<PositionComponent>();


        m_viewPort.x = pos->x + sprite->frameWidth/2 - m_viewPort.w/2;
        m_viewPort.y = pos->y + sprite->frameHeight/2 - m_viewPort.h/2;


        int mapWidth, mapHeight;
        mapWidth = MapParser::instance()->getMapSize().width;
        mapHeight = MapParser::instance()->getMapSize().height;

        if(m_viewPort.x < 0)
        {
            m_viewPort.x = 0;
        }

        if(m_viewPort.y < 0)
        {
            m_viewPort.y = 0;
        }

        if(m_viewPort.x > (mapWidth - m_viewPort.w))
        {
            m_viewPort.x = (mapWidth - m_viewPort.w);
        }

        if(m_viewPort.y > (mapHeight - m_viewPort.h))
        {
            m_viewPort.y = (mapHeight - m_viewPort.h);
        }


        if(m_position == Point2DF(m_viewPort.x, m_viewPort.y))
        {
            return;
        }

        m_position = Point2DF(m_viewPort.x, m_viewPort.y);
    }
}

void Camera::moveTo(Point2DF coord)
{
    auto sprite = ptr_entity->getComponent<SpriteComponent>();
    auto pos     = ptr_entity->getComponent<PositionComponent>();
    pos->x       = coord.getX();
    pos->y       = coord.getY();
}

void Camera::setTarget(EntityID id)
{
    ptr_entity = EntityManager::instance()->getEntityByID(id);
}
}
