#include "CTileRenderer.h"
#include <matrix2D.h>
#include <Parser/TilemapParser/TmxFormat.h>
#include "CTexture2DManager.h"
#include "CTilesetManager.h"

using namespace engine;
CTileRenderer::CTileRenderer()
{

}

void CTileRenderer::render(void *data, float scale)
{
    using _type = std::pair<TmxLayer, Matrix2D<int>>;
    _type *pair = reinterpret_cast<_type*>(data);

    if (pair == nullptr)
    {
        return;
    }

    TmxLayer layer = pair->first;
    Matrix2D<int> matrix = pair->second;

    std::mutex m;
    std::vector<std::thread> threads;

    int CORES = 5;

    //    matrix.print();
    //    printf("\n");

    auto painter = [&](int begin, int end)
    {
        m.lock();

        int index = begin;
        int col, row;

        // cross all cell in the current segment
        for (; index < end; index++)
        {
            // position next tile (x,y)
            col = (index % layer.width); // column
            row = (index / layer.width); // row

            int tileID = matrix.at(index);
            int tileIdx = 0;

            // tileID <= 0 (not tile)
            if (tileID == 0)
            {
                continue;
            }

            const TmxTileSet *tileset;
            for (auto &pair : CTilesetManager::instance()->tilesets())
            {
                if (tileID >= pair.second.first_global_id && tileID < pair.second.first_global_id + pair.second.tile_count)
                {
                    tileset = &pair.second;
                    tileIdx = (tileID - tileset->first_global_id);
                    break;
                }
            }

            int tileX, tileY;
            tileX = (tileIdx % tileset->columns);
            tileY = (tileIdx / tileset->columns);

            float frameX, frameY;
            frameX = col * tileset->tile_width;
            frameY = row * tileset->tile_height;

            CTexture2DManager::instance()->drawTile(tileset->name,
                                                    Point2DF(frameX - layer.offset_x,
                                                             frameY - layer.offset_y),
                                                    tileset->tile_width,
                                                    tileset->tile_height,
                                                    tileY,
                                                    tileX,
                                                    scale);
        }
        m.unlock();
    };

    for (int i = 0; i < CORES; i++)
    {
        // [1] init segment size
        int segmentSize = (layer.width * layer.height) / CORES;

        // [2] init start, end
        int start = i * segmentSize;
        int end = start + segmentSize;

        if (i == CORES - 1)
        {
            end = (layer.width * layer.height);
        }

        threads.push_back(std::thread(painter, start, end));
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    threads.clear();
}
