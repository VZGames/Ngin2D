#ifndef CLAYER_H
#define CLAYER_H

#include "CommonDefine.h"
#include "TilemapParser/tilemap_define.h"
#include "DataStructs/Grid/CGrid.h"

BEGIN_NAMESPACE(engine)
class CLayer: private CGrid<int>
{
private:
    int                     m_id;
    const char*             m_name;
    int                     m_x;
    int                     m_y;
    int                     m_width;
    int                     m_height;
    float                   m_opacity;
    bool                    m_visible;
    int                     m_offset_x;
    int                     m_offset_y;

public:
    explicit CLayer();

    // copy constructor
    CLayer(const CLayer &copy)
    {
        this->m_id = copy.m_id;
        this->m_name = copy.m_name;
        this->m_x = copy.m_x;
        this->m_y = copy.m_y;
        this->m_width = copy.m_width;
        this->m_height = copy.m_height;
        this->m_opacity = copy.m_opacity;
        this->m_visible = copy.m_visible;
        this->m_offset_x = copy.m_offset_x;
        this->m_offset_y = copy.m_offset_y;

    }

    // copy assignment operator
    CLayer &operator=(const CLayer &copy)
    {
        if(this != &copy)
        {
            CLayer layer(copy);
            std::swap(*this, layer);
        }
        return *this;
    }

    // move assignment operator
    CLayer &operator=(CLayer &&other) noexcept
    {
        swap(*this, other);
        return *this;
    }

    friend void swap(CLayer &layer, CLayer& otherLayer) noexcept
    {
        using std::swap;

        std::swap(layer.m_id, otherLayer.m_id);
        std::swap(layer.m_name, otherLayer.m_name);
        std::swap(layer.m_x, otherLayer.m_x);
        std::swap(layer.m_y, otherLayer.m_y);
        std::swap(layer.m_width, otherLayer.m_width);
        std::swap(layer.m_height, otherLayer.m_height);
        std::swap(layer.m_opacity, otherLayer.m_opacity);
        std::swap(layer.m_visible, otherLayer.m_visible);
        std::swap(layer.m_offset_x, otherLayer.m_offset_x);
        std::swap(layer.m_offset_y, otherLayer.m_offset_y);
    }

    static CLayer fromTmxLayer(TmxLayer);

};
END_NAMESPACE

#endif // CLAYER_H
