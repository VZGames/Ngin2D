#include "CSceneManager.h"
#include "AScene.h"

BEGIN_NAMESPACE(GameNgin)
CSceneManager *CSceneManager::s_instance = nullptr;
int CSceneManager::s_scene_count = 0;
CSceneManager::CSceneManager()
{

}

CSceneManager *CSceneManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CSceneManager(): s_instance;
}

int CSceneManager::sceneCount()
{
    return s_scene_count;
}

void CSceneManager::createScene(const char *id, AScene *scene)
{
    scene->m_id = id;
    m_scenes[id] = scene;
}

void CSceneManager::loadScene(const char *id, E_LOAD_SCENE_MODE mode)
{
    m_current_scene_id = id;
    m_scenes.at(id);
    UNUSED(mode)
}

AScene *CSceneManager::currentScene() const
{
    return m_scenes.at(m_current_scene_id);
}

void CSceneManager::init()
{
    for(std::pair<const char*, AScene*> scene: m_scenes)
    {
        scene.second->init();
    }
}

void CSceneManager::update(std::vector<CEntity*> &entities, float dt)
{
    currentScene()->update(entities, dt);
}

void CSceneManager::render()
{
    currentScene()->render();
}
END_NAMESPACE



