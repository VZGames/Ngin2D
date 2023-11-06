#ifndef CCAMERA_H
#define CCAMERA_H

#include "CommonDefine.h"
#include "CommonEnums.h"
#include "offset2D.h"

BEGIN_NAMESPACE(Ngin)
class CEntity;
class AScene;
class CCamera
{
private:
    CCamera();
    static CCamera  *s_instance;
    CEntity         *m_target = nullptr;
    float           m_scale{1.0f};
    Offset          m_offset{0.0f, 0.0f};
public:
    static CCamera *instance();
    void setTarget(CEntity*);
    void update(Offset&);
    Offset offset() const;
    float scale() const;
    void zoom(E_CAMERA_ZOOM, const float&);
};
END_NAMESPACE

#endif // CCAMERA_H
