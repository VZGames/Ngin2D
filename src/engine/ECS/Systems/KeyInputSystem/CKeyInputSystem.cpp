#include "CKeyInputSystem.h"
#include "CEntity.h"
#include "ComponentDef/SKeyInputComponent.h"

BEGIN_NAMESPACE(engine)
CKeyInputSystem::CKeyInputSystem()
{

}

void CKeyInputSystem::init()
{


}

void CKeyInputSystem::update(float dt)
{
    UNUSED(dt)
    std::vector<std::thread> threads;
    // do update for each entity
    auto fn = [&](CEntity* entity){
        auto keyInput = entity->getComponent<SKeyInputComponent>();
        if(!keyInput) return;
        threads.push_back(std::thread(std::bind(&CEntity::handleKeyInput, entity)));
    };
    CWorld::forEachEntities(fn);


    for(std::thread &thread: threads)
    {
        thread.detach();
    }
}

END_NAMESPACE



