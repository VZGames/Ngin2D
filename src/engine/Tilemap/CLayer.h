#ifndef __C_LAYER_H__
#define __C_LAYER_H__

#include "ABase.h"
#include <matrix2D.h>
#include <Parser/TilemapParser/TmxFormat.h>

BEGIN_NAMESPACE(engine)
class CLayer: public ABase
{
private:
    TmxLayer        m_data;
    Matrix2D<int>   m_matrix;

public:
    CLayer(TmxLayer);
    ~CLayer();

    TmxLayer &data();
    Matrix2D<int> &matrix();
};
END_NAMESPACE

#endif // __C_LAYER_H__
