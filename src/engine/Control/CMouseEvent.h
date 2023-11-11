#ifndef CMOUSEEVENT_H
#define CMOUSEEVENT_H

#include "CommonDefine.h"
#include "AEvent.h"

BEGIN_NAMESPACE(engine)
class CMouseEvent: public AEvent
{
private:
    CMouseEvent();
    static CMouseEvent *s_instance;

public:
    static CMouseEvent *instance();

public:
    virtual void processEvents(CEventDispatcher*) override;
};
END_NAMESPACE

#endif // CMOUSEEVENT_H
