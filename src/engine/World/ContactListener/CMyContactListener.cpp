#include "CMyContactListener.h"
#include "Logger/LoggerDefines.h"

BEGIN_NAMESPACE(engine)
CMyContactListener::CMyContactListener()
{

}

void CMyContactListener::BeginContact(b2Contact *contact)
{
    // Handle the beginning of a contact
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();


}

void CMyContactListener::EndContact(b2Contact *contact)
{

}

void CMyContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{

}

void CMyContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{

}
END_NAMESPACE

