#ifndef CTILEMAP_H
#define CTILEMAP_H

#include <stack>
#include <CommonDefine.h>
#include "TilemapParser/CTilemapParser.h"
#include "CObjectLayerManager.h"
#include "ThreadPool/CThreadPool.h"
#include "vector2D.h"
#include "Geometry/AShape.h"

BEGIN_NAMESPACE(engine)
class CEntity;
class CTilesetManager;
class CLayerManager;
class CTilemap
{
private:
    CTilemapParser      m_parser;
    CObjectLayerManager m_object_layer_manager;
    Vector2D<float>     m_coord_limit;
    CLayerManager       *m_layer_manager;
    CTilesetManager     *m_tileset_manager;
    TmxMap              *m_map;
    CThreadPool         *m_pool;

private:
    CTilemap();
    static CTilemap *s_instance;

public:
    ~CTilemap();
    static CTilemap *instance();
    void loadMap(const char* file);
    void update(std::vector<CEntity*> &, float dt);
    void checkCollision(CEntity*);

    TmxMap *map() const;
    Vector2D<float> coord_limit() const;
};
END_NAMESPACE

#endif // CTILEMAP_H
