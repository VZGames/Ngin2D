#ifndef ASCENE_H
#define ASCENE_H

#include "CommonDefine.h"
#include "vector2D.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class ALevel;
class AScene
{
private:
    const char* m_id;
    Vector2D<float> m_boundary;

public:
    friend class CSceneManager;
    const char *id() const;

    virtual void init(){};
    virtual void update(float) {};
    virtual void render() {};

    const Vector2D<float> &boundary() const;
    void setBoundary(const Vector2D<float> &newBoundary);
};
END_NAMESPACE

#endif // ASCENE_H
