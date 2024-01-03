#ifndef CCAMERASYS_H
#define CCAMERASYS_H

#include <CommonDefine.h>
#include <CommonEnums.h>
#include "offset2D.h"
#include "vector2D.h"

BEGIN_NAMESPACE(engine)
class AScene;
class CCameraSys
{
private:
    CCameraSys();
    static CCameraSys   *s_instance;
    Vector2D<float>     m_target;
    float               m_scale{2.0f};
    float               m_view_port_width{0};
    float               m_view_port_height{0};
    Offset              m_offset{0.0f, 0.0f};

public:
    static CCameraSys *instance();
    void setTarget(Vector2D<float>&&);
    Offset *offset();
    const float scale() const;
    float zoom(E_CAMERA_ZOOM, const float& scale = 0.2);
    void viewport(float &, float &);
    void setViewport(float, float);
};
END_NAMESPACE

#endif // CCAMERASYS_H
