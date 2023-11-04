#ifndef CCOMPONENT_H
#define CCOMPONENT_H

#include "CommonDefine.h"
#include "Alias.h"

BEGIN_NAMESPACE(Ngin)
class CComponent
{
private:
    ComponentID                 m_id{MIN_COMPONENT_ID};

protected:
    const char                  *m_name = nullptr;

public:
    CComponent();

    ComponentID id() const;
    void setId(const ComponentID &newId);
    const char *name() const;
};
END_NAMESPACE

#endif // CCOMPONENT_H
