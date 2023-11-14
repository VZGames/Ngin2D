#include "CCustomContactListener.h"
#include "LoggerDefines.h"

BEGIN_NAMESPACE(engine)
CCustomContactListener::CCustomContactListener()
{

}

void CCustomContactListener::BeginContact(b2Contact *contact)
{
    // Handle the beginning of a contact
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

//    DBG("A %f %f", bodyA->GetPosition().x, bodyA->GetPosition().y)
//    DBG("B %f %f", bodyB->GetPosition().x, bodyB->GetPosition().y)
}

void CCustomContactListener::EndContact(b2Contact *contact)
{
    // Handle the ending of a contact
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

//    DBG("A %f %f", bodyA->GetPosition().x, bodyA->GetPosition().y)
//    DBG("B %f %f", bodyB->GetPosition().x, bodyB->GetPosition().y)

}

void CCustomContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
    UNUSED(contact)
    UNUSED(oldManifold)
}

void CCustomContactListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
    UNUSED(contact)
    UNUSED(impulse)
}
END_NAMESPACE

