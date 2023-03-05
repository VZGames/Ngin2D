//#include "EventInputSystem.h"

//#include "../../Components/Components.h"
//#include "../../Entity/EntityManager.h"
//#include "../../Components/ComponentManager.h"
//#include "../../../Listener/Events.h"
//#include "../../../Game/Game.h"

//namespace ngin2D
//{
//EventInputSystem::EventInputSystem()
//{

//}

//void EventInputSystem::update(float dt)
//{

//    for(Entity entity: EntityManager::instance()->getEntities())
//    {
//        bool isPlayer = ComponentManager::instance()->hasComponentType<PlayerComponent>(entity.componentBitset);
//        bool hasComponent = ComponentManager::instance()->hasComponentType<MotionComponent>(entity.componentBitset);
//        hasComponent &= ComponentManager::instance()->hasComponentType<SpriteComponent>(entity.componentBitset);

//        auto motion = entity.getComponent<MotionComponent>();
//        auto sprite = entity.getComponent<SpriteComponent>();

//        if(isPlayer && hasComponent)
//        {
//            KeyEvent::instance()->listen();
//            motion->velocity = Vector2I(0, 0);

//            if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_A))
//            {
//                motion->velocity.x += 1 * LEFT;
//                sprite->row = 2;
//                sprite->col = 2;
//            }

//            if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_D))
//            {
//                motion->velocity.x += 1 * RIGHT;
//                sprite->row = 3;
//                sprite->col = 2;
//            }

//            if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_W))
//            {
//                motion->velocity.y += 1 * UP;
//                sprite->row = 1;
//                sprite->col = 2;
//            }

//            if(KeyEvent::instance()->sendEvent(SDL_SCANCODE_S))
//            {
//                motion->velocity.y += 1 * DOWN;
//                sprite->row = 0;
//                sprite->col = 2;
//            }
//        }
//    }
//}
//}
