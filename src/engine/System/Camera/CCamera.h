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
    static CCamera *s_instance;
    Offset m_offset{0.0f, 0.0f};
    CEntity *m_target = nullptr;
public:
    static CCamera *instance();
    void setTarget(CEntity*);
    void update(Offset&);
    Offset offset() const;
    void zoom(E_CAMERA_ZOOM, float);
};
END_NAMESPACE

#endif // CCAMERA_H
