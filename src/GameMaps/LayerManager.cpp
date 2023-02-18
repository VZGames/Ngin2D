#include "LayerManager.h"
#include <string>
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

    auto worker = [&](int core, Layer layer) {
        fflush(stdout);

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

        int posX = start % layer.width; // [0, 337] [337, 7XX]
        int posY = start / layer.width;


        printf("Layer Name: %s, Width: %d, Height: %d, Start: %d, End: %d, X: %d, Y: %d\n",
               layer.name, layer.width, layer.height, start, end, posX, posY);
        for (int i = start; i < end; i++)
        {
            tileID = data[i];
            TileSet tileset = MapParser::instance()->findById(tileID);
            if(posX > layer.width)
            {
                posX  = 0;
                posY++;
            }
            if(posY > layer.height)
            {
                posY = layer.height;
            }

            int frameX, frameY;
            frameX = (tileID - ((tileset.columns + tileset.firstgid) - 1)) * (-1); // [0, 1, 2, ..., N]
            frameY = 0;

            TextureManager::instance()->drawTile(
                        tileset.name,
                        tileset.tileWidth,
                        tileset.tileHeight,
                        Point2D(posX * tileset.tileWidth, posY * tileset.tileHeight),
                        frameX,
                        0);
            posX++;

        }
    };

    for(auto layer: layers)
    {
        for (int i = 0; i < CORES; i++) {
            threads.push_back(std::thread(worker, i, layer));
        }

        for(auto &thread:threads)
        {
            thread.join();
        }

        threads.clear();
        break;
    }
}

void LayerManager::update()
{

}
