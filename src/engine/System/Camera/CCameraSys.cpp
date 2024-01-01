#include "Camera/CCameraSys.h"
#include <LoggerDefines.h>

using namespace engine;
CCameraSys *CCameraSys::s_instance = nullptr;
CCameraSys::CCameraSys()
{

}

CCameraSys *CCameraSys::instance()
{
    return s_instance = (s_instance == nullptr)? new CCameraSys():s_instance;
}

void CCameraSys::setTarget(Vector2D<float> &&target)
{
    m_offset.Zeros();
    m_target = target;
}

Offset *CCameraSys::offset()
{
    return &m_offset;
}

float CCameraSys::scale() const
{
    return m_scale;
}

float CCameraSys::zoom(E_CAMERA_ZOOM mode, const float &scale)
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
    return m_scale;
}

void CCameraSys::viewport(float &width, float &height)
{
    width = m_view_port_width;
    height = m_view_port_height;
}

void CCameraSys::setViewport(float width, float height)
{
    m_view_port_width = width;
    m_view_port_height = height;
}












