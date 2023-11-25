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
    m_offset = newOffset;
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
        if(m_scale > 2) m_scale = 2;
    }
    else if(mode == E_CAMERA_ZOOM::ZOOM_OUT)
    {
        m_scale -= scale;
        if(m_scale < 1) m_scale = 1;
    }
    return;
}
END_NAMESPACE








