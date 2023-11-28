#ifndef CLEVELMANAGER_H
#define CLEVELMANAGER_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(engine)
class CLevelManager
{
public:
    CLevelManager();

    void loadLevel(const char* id);
};
END_NAMESPACE

#endif // CLEVELMANAGER_H
