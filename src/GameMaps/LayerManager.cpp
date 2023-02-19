#include "LayerManager.h"
#include <string>
#include <cmath>
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
    std::vector<Layer> layers = MapParser::instance()->getLayers();
    //    for(auto layer: layers)
    //    {
    //        int *data = layer.data;
    //        for (int row = 0; row < layer.height; row++) {
    //            for (int col = 0; col < layer.width; col++) {

    //                int tileID = data[row * layer.width + col];

    //                if(tileID == 0)
    //                {
    //                    continue;
    //                }

    //                TileSet tileset;
    //                MapParser::instance()->findById(tileID, tileset);

    //                tileID = (tileID - tileset.firstgid);

    //                int tileX, tileY;
    //                tileX = (tileID % tileset.columns);
    //                tileY = tileID / tileset.columns;

    //                TextureManager::instance()->drawTile(
    //                            tileset.name,
    //                            tileset.tileWidth,
    //                            tileset.tileHeight,
    //                            Point2D(col * tileset.tileWidth, row * tileset.tileHeight),
    //                            tileY,
    //                            tileX);

    //            }
    //        }
    //    }


    std::mutex m;
    auto worker = [&](int core, Layer layer) {
        m.lock();

        // [1] init segment size
        int segmentSize = (layer.width * layer.height) / CORES;

        // [2] init (start, end)
        int start   = core * segmentSize;
        int end     = start + segmentSize;

        // [3]
        int *data   = layer.data;
        int tileID;

        if(core == CORES - 1)
        {
            end = layer.width * layer.height;
        }

        int col, row;
        col = start % layer.width;
        row = start / layer.width;

        fflush(stdout);
        printf("Layer Name: %s, Width: %d, Height: %d, Start: %d, End: %d, X: %d, Y: %d\n",
               layer.name, layer.width, layer.height, start, end, col, row);


        for (int i = start; i < end; i++)
        {
            tileID = data[i];
            if(tileID == 0)
            {
                continue;
            }

            TileSet tileset;
            MapParser::instance()->findById(tileID, tileset);

            tileID = (tileID - tileset.firstgid); // real id

            int tileX, tileY;
            tileX = (tileID % tileset.columns);
            tileY = tileID / tileset.columns;

            TextureManager::instance()->drawTile(
                        tileset.name,
                        tileset.tileWidth,
                        tileset.tileHeight,
                        Point2D(col * tileset.tileWidth, row * tileset.tileHeight),
                        tileY,
                        tileX);

            if(col > layer.width)
            {
                if(row < layer.height)
                    row++;
            }
            else
            {
                col++;
            }
        }
        m.unlock();
    };

    for(auto layer: layers)
    {
        std::vector<std::thread> threads;

        for (int i = 0; i < CORES; i++) {
            threads.push_back(std::thread(worker, i, layer));
        }

        for(auto &thread:threads)
        {
            thread.join();
        }

        threads.clear();
    }
}

void LayerManager::update()
{

}
