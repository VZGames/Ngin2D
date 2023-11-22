#include "CCamera.h"
#include "CEntity.h"
#include "ComponentDef/SPositionComponent.h"

BEGIN_NAMESPACE(engine)
CCamera *CCamera::s_instance = nullptr;
CCamera::CCamera()
{

}

CCamera *CCamera::instance()
{
    return s_instance = (s_instance == nullptr)? new CCamera():s_instance;
}

void CCamera::setTarget(CEntity *entity)
{
    m_offset.zero();
    m_target = entity;
}

void CCamera::update(Offset &newOffset)
{
    if(m_target == nullptr) return;
    if(!m_target->hasComponent<SPositionComponent>()) return;
    SPositionComponent *position = m_target->getComponent<SPositionComponent>();
    m_offset = newOffset;
    position->x -= m_offset.getX();
    position->y -= m_offset.getY();

}

Offset CCamera::offset() const
{
    return m_offset;
}

float CCamera::scale() const
{
    return m_scale;
}

void CCamera::zoom(E_CAMERA_ZOOM mode, const float &scale)
{
    if(mode == E_CAMERA_ZOOM::ZOOM_IN)
    {
        m_scale += scale;
    }
    else if(mode == E_CAMERA_ZOOM::ZOOM_OUT)
    {
        m_scale -= scale;
    }
    return;
}
END_NAMESPACE








