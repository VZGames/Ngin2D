#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H

#include "MapParser.h"

namespace ngin2D {
class LayerManager
{
public:
    static LayerManager *instance();
    void draw();
    void update();

private:
    LayerManager();
    static LayerManager *s_instance;
};
}


#endif // LAYERMANAGER_H
