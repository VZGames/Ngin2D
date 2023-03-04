#include "EventInputSystem.h"

#include "../../Components/Components.h"
#include "../../Entity/EntityManager.h"
#include "../../Components/ComponentManager.h"
#include "../../../Game/Game.h"

namespace ngin2D
{
EventInputSystem::EventInputSystem()
{
    keyBoardState = SDL_GetKeyboardState(nullptr);
}

void EventInputSystem::update(float dt)
{

    for(Entity entity: EntityManager::instance()->getEntities())
    {
        bool isPlayer = ComponentManager::instance()->hasComponentType<PlayerComponent>(entity.componentBitset);
        if(isPlayer)
        {
            bool isKeyDown = (event.type == SDL_KEYDOWN);
            std::cout << isKeyDown << std::endl;
            auto motion = entity.getComponent<MotionComponent>();
            if(keyBoardState[SDL_SCANCODE_A])
            {
                motion->velocity.x = 3 * (int)isKeyDown;
                motion->direction  = -1;
            }
            if(keyBoardState[SDL_SCANCODE_W])
            {

            }
            if(keyBoardState[SDL_SCANCODE_S])
            {

            }
            if(keyBoardState[SDL_SCANCODE_D])
            {
                motion->velocity.x = 3 * (int)isKeyDown;
                motion->direction  = 1;
            }
            break;
        }
    }
}
}
