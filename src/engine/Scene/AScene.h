#ifndef ASCENE_H
#define ASCENE_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(engine)
class AScene
{
private:
    const char* m_id;

public:
    friend class CSceneManager;
    const char *id() const;

    virtual void init(){};
    virtual void update(float) {};
};
END_NAMESPACE

#endif // ASCENE_H
