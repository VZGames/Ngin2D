#ifndef CCOMPONENT_H
#define CCOMPONENT_H

#include <CommonDefine.h>
#include <Alias.h>
#include <ABase.h>

BEGIN_NAMESPACE(engine)
class CComponent: public ABase
{
private:
    ComponentID                 m_id{MIN_COMPONENT_ID};

public:
    CComponent(const char*);
    ~CComponent();

    ComponentID id() const;
    void setId(const ComponentID &newId);
};
END_NAMESPACE

#endif // CCOMPONENT_H
