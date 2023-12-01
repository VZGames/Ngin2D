#ifndef CLEVELMANAGER_H
#define CLEVELMANAGER_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(engine)
class ALevel;
class CLevelManager
{
private:
    std::unordered_map<const char*, ALevel*> m_levels;

private:
    CLevelManager();
    static CLevelManager* s_instance;

public:
    static CLevelManager* instance();
    void loadLevel(const char* id);
    void update(float dt);
    void render();
};
END_NAMESPACE

#endif // CLEVELMANAGER_H
