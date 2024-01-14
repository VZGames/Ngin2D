#include "CLayer.h"

using namespace engine;

CLayer::CLayer(TmxLayer data): m_data(data)
{
    m_class_name = __FUNCTION__;
    m_matrix     = Matrix2D<int>::fromString(m_data.data->content, data.height, data.width);
    DBG("Init instance %s At address [%p] %s", m_class_name, this, m_data.name)
}

CLayer::~CLayer()
{
}

TmxLayer &CLayer::data()
{
    return m_data;
}

Matrix2D<int> &CLayer::matrix()
{
    return m_matrix;
}
