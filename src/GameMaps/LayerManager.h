#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H


#include <thread>
#include <mutex>
#include <vector>
#include "MapParser.h"

class LayerManager
{
public:
    static LayerManager *instance();
    void draw();
    void update();

private:
    LayerManager();
    static LayerManager *s_instance;

    std::vector<std::thread> threads;
    std::mutex mux;

};

#endif // LAYERMANAGER_H
