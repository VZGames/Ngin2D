#include "CCameraSys.h"

BEGIN_NAMESPACE(engine)
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

void CCameraSys::update(Offset &newOffset)
{
    m_offset = newOffset;
}

Offset CCameraSys::offset() const
{
    return m_offset;
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
END_NAMESPACE








