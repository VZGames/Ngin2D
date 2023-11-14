#ifndef CCUSTOMCONTACTLISTENER_H
#define CCUSTOMCONTACTLISTENER_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(engine)
class CCustomContactListener: public b2ContactListener
{
public:
    CCustomContactListener();

    // b2ContactListener interface
public:
    virtual void BeginContact(b2Contact *contact) override;
    virtual void EndContact(b2Contact *contact) override;
    virtual void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;
    virtual void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) override;
};
END_NAMESPACE

#endif // CCUSTOMCONTACTLISTENER_H
