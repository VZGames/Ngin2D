#include "CLayer.h"

using namespace engine;

CLayer::CLayer(TmxLayer data): m_data(data)
{
    m_derived_class_name = __FUNCTION__;
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
