#ifndef ASCENE_H
#define ASCENE_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class ALevel;
class AScene
{
private:
    const char* m_id;

public:
    friend class CSceneManager;
    const char *id() const;

    virtual void init(){};
    virtual void update(float) {};
    virtual void render() {};
};
END_NAMESPACE

#endif // ASCENE_H
