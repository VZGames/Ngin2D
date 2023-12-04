#include "CGameScene.h"
#include "CSceneManager.h"
#include "LoggerDefines.h"
#include "CECSystemManager.h"
#include "CRenderSys.h"
#include "CBroadPhaseCulling.h"
#include "ComponentDef/SPositionComponent.h"
#include "TilemapParser/CTilemapParser.h"


BEGIN_NAMESPACE(script)
CGameScene::CGameScene()
    :m_grid_layout(16, 30, 30)
{
    engine::CSceneManager::instance()->createScene(__FUNCTION__, this);
}

void CGameScene::init()
{
    // space init entities
    {
        cow.setPosition(200, 50);
        cow2.setPosition(320, 100);
        cow3.setPosition(640, 400);

        m_entities.emplace_back(&player);
        m_entities.emplace_back(&cow);
        m_entities.emplace_back(&cow2);
        m_entities.emplace_back(&cow3);

        for(auto &entity: m_entities)
        {
            engine::CWorld::instance()->registerEntity(entity);

            auto position = entity->getComponent<engine::SPositionComponent>();

            if(position == nullptr) continue;
            engine::CBroadPhaseCulling::instance()->insert(entity->id(),position->x, position->y);
        }

        engine::CECSystemManager::instance()->init(m_entities);
    }


    // space init map/level
    {
        CTilemapParser parser;
        parser.loadFile("./debug/assets/Maps/PhuHoa.tmx");

        int mapWidth = parser.map().width;
        int mapHeight = parser.map().height;

        m_grid_layout.resize(mapHeight, mapWidth);

        std::vector<TmxTileSet>         tilesets(parser.countWith("tileset"));
        std::vector<TmxLayer>           layers(parser.countWith("layer"));

        TmxTileSet tileset;
        TmxLayer layer;

        for(int i = 0; i < static_cast<int>(tilesets.size()); i++)
        {
            parser.parse(i, tileset);
            tilesets[i] = std::move(tileset);
        }

        for(int i = 0; i < static_cast<int>(layers.size()); i++)
        {
            parser.parse(i, layer);
            layers[i] = std::move(layer);

            Matrix2D<int> matrix = Matrix2D<int>::fromString(layers[i].data->content, layer.height, layer.width);

            for(int r = 0; r < layer.height; r++)
            {
                for(int c = 0; c < layer.width; c++)
                {
                    m_grid_layout.insertTileForLayer(matrix.at(r, c), layer.x, layer.y);
                }
            }
        }
    }
}

void CGameScene::update(float dt)
{
    engine::CBroadPhaseCulling::instance()->clean();
    engine::CECSystemManager::instance()->update(m_entities, dt);
}

void CGameScene::render()
{
    std::sort(m_entities.begin(), m_entities.end(), [](const engine::CEntity *A, const engine::CEntity *B){
        auto spriteA     = A->getComponent<engine::SSpriteComponent>();
        auto spriteB     = B->getComponent<engine::SSpriteComponent>();
        return spriteA->zOrder < spriteB->zOrder;
    });
    // [1] create new thread for render map
    for(engine::CEntity *entity: m_entities)
    {
        engine::CRenderSys::instance()->drawEntity(entity);
    }

    // [2] wait for all finished

}

END_NAMESPACE



