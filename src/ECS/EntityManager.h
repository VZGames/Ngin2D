#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <queue>
#include "../Defines/Alias.h"

class EntityManager
{
public:
    static EntityManager *instance();
private:
    EntityManager();
    static EntityManager *s_instance;
};

#endif // ENTITYMANAGER_H
