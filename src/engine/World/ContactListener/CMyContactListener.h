#ifndef CMYCONTACTLISTENER_H
#define CMYCONTACTLISTENER_H

#include "CommonDefine.h"

BEGIN_NAMESPACE(engine)
class CMyContactListener: public b2ContactListener
{
public:
    CMyContactListener();

    // b2ContactListener interface
public:
    virtual void BeginContact(b2Contact *contact) override;
    virtual void EndContact(b2Contact *contact) override;
    virtual void PreSolve(b2Contact *contact, const b2Manifold *oldManifold) override;
    virtual void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) override;
};
END_NAMESPACE

#endif // CMYCONTACTLISTENER_H
