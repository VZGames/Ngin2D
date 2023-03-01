#include "MovementSystem.h"

namespace ngin2D {
MovementSystem *MovementSystem::s_instance = nullptr;
MovementSystem *MovementSystem::instance()
{
    return s_instance = (s_instance == nullptr)? new MovementSystem(): s_instance;
}

MovementSystem::MovementSystem()
{

}

void MovementSystem::update(float dt)
{

}


}
