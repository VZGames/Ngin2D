#include <iostream>
#include "CNgin.h"
#include "CWorld.h"
#include "LoggerDefines.h"
#include "CSceneManager.h"
#include "SceneObjects/CGameScene.h"
#include "SceneObjects/CSettingScene.h"
#include "XMLParser/CXmlParser.h"
#include "LoggerDefines.h"

using namespace engine;

int main(int argc, char *argv[])
{
    UNUSED(argc)
    UNUSED(argv)

    // Script
    CXmlParser parser;
    parser.loadFile("./debug/assets/Maps/PhuHoa.tmx");

    int tilewidth = std::stoi(parser.rootAttribute("tilewidth"));
    int tileheight = std::stoi(parser.rootAttribute("tileheight"));
    int cols = std::stoi(parser.rootAttribute("width"));
    int rows = std::stoi(parser.rootAttribute("height"));

    script::CGameScene gameScene;
    script::CSettingScene settingScene;

    CSceneManager::instance()->loadScene(gameScene.id(), E_LOAD_SCENE_MODE::SINGLE);

    if(engine::CNgin::instance()->initialize("Game Framework", (cols * tilewidth), (rows * tileheight), engine::CWorld::instance()))
    {
        engine::CNgin::instance()->loop();
        engine::CNgin::instance()->clean();
        engine::CNgin::instance()->quit();
    }
    else
    {
        DBG("Can't initialize Game Game");
    }
    return 0;
}
