#ifndef CLEVELMANAGER_H
#define CLEVELMANAGER_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(engine)
class ALevel;
class CLevelManager
{
private:
    std::unordered_map<const char*, ALevel*> m_levels;
    const char* m_current_level_id;
private:
    CLevelManager();
    static CLevelManager* s_instance;

public:
    static CLevelManager* instance();
    void createLevel(const char* id, ALevel* level);
    void loadLevel(const char* id);
    ALevel* currentLevel() const;
};
END_NAMESPACE

#endif // CLEVELMANAGER_H
