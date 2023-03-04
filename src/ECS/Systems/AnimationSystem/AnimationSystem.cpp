#include "AnimationSystem.h"
#include "../../Entity/EntityManager.h"
#include "../../Components/Components.h"
#include "../../Components/ComponentManager.h"
#include "../../../Graphics/TextureManager/TextureManager.h"

namespace ngin2D {
AnimationSystem::AnimationSystem()
{

}

void AnimationSystem::update(float dt)
{
    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool hasComponent = ComponentManager::instance()->hasComponentType<SpriteComponent>(entity.componentBitset);
        if(hasComponent)
        {
        }
    }
}
}

