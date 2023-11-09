#ifndef CSCENEMANAGER_H
#define CSCENEMANAGER_H

#include "CommonDefine.h"
#include "CommonEnums.h"

BEGIN_NAMESPACE(engine)
class AScene;
class CEntity;
class CSceneManager
{
private:
    CSceneManager();
    static CSceneManager                *s_instance;
    static int                          s_scene_count;
    std::map<const char*, AScene*>      m_scenes;
    const char*                         m_current_scene_id;
public:
    static CSceneManager* instance();
    static int sceneCount();
    void createScene(const char*, AScene*);
    void loadScene(const char*, E_LOAD_SCENE_MODE);
    AScene* currentScene() const;
};
END_NAMESPACE

#endif // CSCENEMANAGER_H
