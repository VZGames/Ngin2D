#ifndef ASCENE_H
#define ASCENE_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(engine)
class AScene
{
public:
    friend class CSceneManager;
    const char *id() const;

    virtual void init(){};
private:
    const char* m_id;
};
END_NAMESPACE

#endif // ASCENE_H
