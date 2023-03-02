#include "Scene.h"

namespace ngin2D {
Scene *Scene::s_instance = nullptr;
Scene *Scene::instance()
{
    return s_instance = (s_instance == nullptr)? new Scene(): s_instance;
}

Scene::Scene()
{}
}
