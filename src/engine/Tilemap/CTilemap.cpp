#include "CTilemap.h"
#include "CTilesetManager.h"
#include "CLayerManager.h"
#include "Camera/CCameraSys.h"
#include "CEntity.h"
#include "ComponentDef/SBoxComponent.h"
#include "ComponentDef/SMotionComponent.h"

using namespace engine;
CTilemap *CTilemap::s_instance = nullptr;
CTilemap::CTilemap()
{
    m_tileset_manager = CTilesetManager::instance();
    m_layer_manager = CLayerManager::instance();
}

CTilemap::~CTilemap()
{
    m_pool->shutdown();
    safeRelease(m_tileset_manager);
}

CTilemap *CTilemap::instance()
{
    return s_instance = (s_instance == nullptr) ? new CTilemap() : s_instance;
}

void CTilemap::loadMap(const char *file)
{
    DBG("[START] LOAD MAP")
    m_parser.loadFile(file);
    m_map = &m_parser.map();

    m_coord_limit.x = m_map->width * m_map->tile_width;
    m_coord_limit.y = m_map->height * m_map->tile_height;

    int tilesetNum = 0;
    int layerNum = 0;
    int objectNum = 0;

    tilesetNum = m_parser.countWith("tileset");
    layerNum = m_parser.countWith("layer");
    objectNum = m_parser.countWith("objectgroup.object");

    m_pool = new CThreadPool(layerNum);
    m_pool->init();

    m_tileset_manager->clear();

    for (int i = 0; i < tilesetNum; i++)
    {
        TmxTileSet tmxTileset;
        m_parser.parse(i, tmxTileset);
        m_tileset_manager->insert(tmxTileset.name, std::move(tmxTileset));
    }

    m_layer_manager->clear();

    for (int i = 0; i < layerNum; i++)
    {
        TmxLayer tmxLayer;
        m_parser.parse(i, tmxLayer);
        m_layer_manager->push(std::move(tmxLayer));
    }

    for (int i = 0; i < objectNum; i++)
    {
        TmxObject tmxObject;
        m_parser.parse(i, tmxObject);
        m_object_layer_manager.push(std::move(tmxObject));
    }
    DBG("[END] LOAD MAP")
}

void CTilemap::update(std::vector<CEntity *> &entities, float dt)
{
    UNUSED(dt)

    Offset *offset = CCameraSys::instance()->offset();

    for (auto &data : m_layer_manager->layers())
    {
        data.first.offset_x = offset->x + dt;
        data.first.offset_y = offset->y + dt;
    }

    for (CEntity *entity : entities)
    {
        checkCollision(entity);
    }
}

void CTilemap::checkCollision(CEntity *entity)
{
    auto motion = entity->getComponent<SMotionComponent>();
    auto box = entity->getComponent<SBoxComponent>();
    m_object_layer_manager.checkCollision(&box->shape, motion->mtv);
}

TmxMap *CTilemap::map() const
{
    return m_map;
}

Vector2D<float> CTilemap::coord_limit() const
{
    return m_coord_limit;
}
