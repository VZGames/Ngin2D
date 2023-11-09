#ifndef CCOMPONENTMANAGER_H
#define CCOMPONENTMANAGER_H

#include "CComponent.h"

BEGIN_NAMESPACE(engine)
class CComponentManager
{
private:
    CComponentManager();

    static CComponentManager                        *s_instance;
    ComponentID                                     m_component_count{MIN_COMPONENT_COUNT};
    std::queue<ComponentID>                         m_available_ids;
    std::unordered_map<const char*, ComponentID>    m_dictionary;

public:
    static CComponentManager                    *instance();

    bool createComponent(CComponent*);
};
END_NAMESPACE

#endif // CCOMPONENTMANAGER_H
