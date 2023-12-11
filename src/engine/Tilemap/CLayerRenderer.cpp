#include "CLayerRenderer.h"
#include "matrix2D.h"
#include "LoggerDefines.h"
#include "CTexture2DManager.h"
#include "CCameraSys.h"

BEGIN_NAMESPACE(engine)
CLayerRenderer::CLayerRenderer()
{

}


void CLayerRenderer::render(const std::unordered_map<const char*, TmxTileSet> &tilesetMap,TmxLayer &layer, Matrix2D<int>&& matrix)
{
    std::mutex m;
    std::vector<std::thread> threads;

    int CORES = 5;

//    matrix.print();
//    printf("\n");

    auto painter = [&](int begin, int end){
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
            if(tileID == 0)
            {
                continue;
            }

            const TmxTileSet *tileset;
            for(auto &pair: tilesetMap)
            {
                if(tileID >= pair.second.first_global_id && tileID < pair.second.first_global_id + pair.second.tile_count)
                {
                    tileset = &pair.second;
                    tileIdx = (tileID - tileset->first_global_id);
                    break;
                }
            }

            int tileX, tileY;
            tileX = (tileIdx % tileset->columns);
            tileY = (tileIdx / tileset->columns);

            float x, y;
            x = layer.x + (col * tileset->tile_width);
            y = layer.y + (row * tileset->tile_height);

            CTexture2DManager::instance()->drawTile(tileset->name,
                                                    Point2DF(x,  y),
                                                    tileset->tile_width,
                                                    tileset->tile_height,
                                                    tileY,
                                                    tileX);
        }
        m.unlock();
    };

    for (int i = 0; i < CORES; i++)
    {
        // [1] init segment size
        int segmentSize = (layer.width  * layer.height) / CORES;

        // [2] init start, end
        int start   = i  *segmentSize;
        int end     = start + segmentSize;

        if(i == CORES - 1)
        {
            end = (layer.width * layer.height);
        }

        threads.push_back(std::thread(painter, start, end));
    }


    for(auto &thread:threads)
    {
        thread.join();
    }

    threads.clear();

}
END_NAMESPACE



