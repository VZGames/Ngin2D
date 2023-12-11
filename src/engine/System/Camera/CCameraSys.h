#ifndef CCAMERASYS_H
#define CCAMERASYS_H

#include "CommonDefine.h"
#include "CommonEnums.h"
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
    Vector2D<int>       m_viewport;
    float               m_scale{2.0f};
    Offset              m_offset{0.0f, 0.0f};

public:
    static CCameraSys *instance();
    void setTarget(Vector2D<float>&&);
    void update(Offset&);
    Offset offset() const;
    float scale() const;
    float zoom(E_CAMERA_ZOOM, const float& scale = 0.2);
};
END_NAMESPACE

#endif // CCAMERASYS_H
