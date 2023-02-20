#include "LayerManager.h"
#include <string>
#include <time.h>
#include <thread>
#include <mutex>
#include "../Math/math2D.h"
#include "../Defines/Defines.h"
#include "../Graphics/TextureManager/TextureManager.h"

LayerManager *LayerManager::s_instance = nullptr;

LayerManager::LayerManager()
{
    std::vector<TileSet> tilesets   = MapParser::instance()->getTilesets();
    for(auto tileset: tilesets)
    {
        std::string imgSrc    = tileset.image.src;
        std::string filePath        = "./assets/" + imgSrc;
        TextureManager::instance()->loadTexture(tileset.name, filePath.c_str());
    }
}

LayerManager *LayerManager::instance()
{
    return s_instance = (s_instance == nullptr)? new LayerManager():s_instance;
}

void LayerManager::draw()
{
    std::clock_t t;
    t = clock();

    std::vector<Layer> layers = MapParser::instance()->getLayers();

    /**
     * Draw with multi threads
     */

    std::mutex m;
    auto worker = [&](int i, int j, Layer layer, Matrix2D<int>data) {
        m.lock();
        for (; i < j; i++)
        {
            // position next tile (x,y)
            int x, y;
            x = (i % layer.width);
            y = (i / layer.width);


            int tileID = data.at(i);
            if(tileID == 0)
            {
                continue;
            }

            TileSet tileset;
            MapParser::instance()->findById(tileID, tileset);

            tileID = (tileID - tileset.firstgid);


            int tileX, tileY;
            tileX = (tileID % tileset.columns);
            tileY = (tileID / tileset.columns);

            TextureManager::instance()->drawTile(
                        tileset.name,
                        tileset.tileWidth,
                        tileset.tileHeight,
                        Point2D(x * tileset.tileWidth, y * tileset.tileHeight),
                        tileY,
                        tileX);

        }
        m.unlock();
    };

    for(auto layer: layers)
    {
        std::vector<std::thread> threads;
        for (int i = 0; i < CORES; i++) {

            // [1] init segment size
            int segmentSize = (layer.width * layer.height) / CORES;

            // [2] init start, end
            int start   = i * segmentSize;
            int end     = start + segmentSize;

            // [3]
//            int *data   = layer.data;
            Matrix2D<int> data(layer.data);

            if(i >= CORES - 1)
            {
                end = (layer.width * layer.height);
            }

            //            fflush(stdout);
            //            printf("Layer Name: %s, Width: %d, Height: %d, Start: %d, End: %d\n",
            //                   layer.name, layer.width, layer.height, start, end);

            threads.push_back(std::thread(worker, start, end, layer, data));
        }

        for(auto &thread:threads)
        {
            thread.join();
        }

        threads.clear();
    }


    t = clock() - t;
    std::cout << "Render Map - It took time " << ((float)t) / CLOCKS_PER_SEC << std::endl;
}

void LayerManager::update()
{

}
