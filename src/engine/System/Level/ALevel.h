#ifndef ALEVEL_H
#define ALEVEL_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(engine)
class ALevel
{
protected:
    const char* m_name;

public:
    const char* name() const;
public:
    virtual void update(float) {};
    virtual void render() {};
};
END_NAMESPACE

#endif // ALEVEL_H
