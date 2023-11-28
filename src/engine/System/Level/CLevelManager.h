#ifndef CLEVELMANAGER_H
#define CLEVELMANAGER_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(engine)
class CLevelManager
{
private:
    CLevelManager();
    static CLevelManager* s_instance;

public:
    static CLevelManager* instance();
    void loadLevel(const char* id);
    void update(float dt);
};
END_NAMESPACE

#endif // CLEVELMANAGER_H
