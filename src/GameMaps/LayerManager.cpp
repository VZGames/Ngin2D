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
        std::string assetsFolder    = "./assets/";
        std::string filePath        = assetsFolder + tileset.image.src;
        bool loadOK = TextureManager::instance()->load(tileset.name, filePath.c_str());
        if(!loadOK)
        {
            std::cerr << "ERROR\n";
            return;
        }
    }
}

LayerManager *LayerManager::instance()
{
    return s_instance = (s_instance == nullptr)? new LayerManager():s_instance;
}

void LayerManager::draw()
{
    std::vector<Layer> layers       = MapParser::instance()->getLayers();

    auto worker = [&](int core, Layer layer) {
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
            end     = layer.width * layer.height;
        }

        for (int i = start; i < end; i++) {
            tileID = data[i];
            TextureManager::instance()->draw_tile("Water", 16, Point2D(100,200), 0, 0);
            break;
        }
    };

    for(auto layer: layers)
    {
        for (int i = 0; i < CORES; i++) {
            threads.push_back(std::thread(worker, i, layer));
        }
    }

    for(auto &thread:threads)
    {
        thread.join();
    }

    threads.clear();

}

void LayerManager::update()
{

}
