#ifndef CECSYSTEMMANAGER_H
#define CECSYSTEMMANAGER_H

#include "CommonDefine.h"
#include "Systems/IECSystem.h"

BEGIN_NAMESPACE(GameNgin)
class CECSystemManager
{
private:
    CECSystemManager();
    static CECSystemManager                   *s_instance;
    std::vector<IECSystem*>                 m_systems;

public:
    static CECSystemManager *instance();

};
END_NAMESPACE

#endif // CECSYSTEMMANAGER_H
