#include "CSceneManager.h"
#include "AScene.h"
#include "CWorld.h"
#include "CBroadPhaseCulling.h"

BEGIN_NAMESPACE(engine)
CSceneManager *CSceneManager::s_instance = nullptr;
int CSceneManager::s_scene_count = 0;
CSceneManager::CSceneManager()
{
    CBroadPhaseCulling::instance(512, 512, 30, 30);
}

CSceneManager *CSceneManager::instance()
{
    return s_instance = (s_instance == nullptr)? new CSceneManager(): s_instance;
}

int CSceneManager::sceneCount()
{
    return s_scene_count;
}

AScene* CSceneManager::createScene(const char *id, AScene *scene)
{
    if(scene == nullptr) return nullptr;
    if(m_scenes.find(id) != m_scenes.end()) return nullptr;
    else
    {
        scene->m_id = id;
        m_scenes[id] = scene;
        CWorld::instance()->registerScene(m_scenes[id]);
    }
    return m_scenes[id];
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

void CSceneManager::transition(const char *)
{

}

END_NAMESPACE




