#include "CTilemapParser.h"
#include "Utils.h"

CTilemapParser::CTilemapParser()
{

}

CTilemapParser::~CTilemapParser()
{
//    safeRelease(m_map.tilesets->image);
//    safeRelease(m_map.layers->data);
    safeRelease(m_map.tilesets);
    safeRelease(m_map.layers);
}

void CTilemapParser::loadFile(const char *file)
{
    m_xmlparser.loadFile(file);

    m_map.orientation       = m_xmlparser.rootAttribute("orientation");
    m_map.render_order      = m_xmlparser.rootAttribute("renderorder");
    m_map.width             = std::stoi(m_xmlparser.rootAttribute("width"));
    m_map.height            = std::stoi(m_xmlparser.rootAttribute("height"));
    m_map.tile_width        = std::stoi(m_xmlparser.rootAttribute("tilewidth"));
    m_map.tile_height       = std::stoi(m_xmlparser.rootAttribute("tileheight"));
    m_map.next_layer_id     = std::stoi(m_xmlparser.rootAttribute("nextlayerid"));
    m_map.next_object_id    = std::stoi(m_xmlparser.rootAttribute("nextobjectid"));
    m_map.tilesets          = new TmxTileSet[m_xmlparser.count("tileset")];
    m_map.layers            = new TmxLayer[m_xmlparser.count("layer")];
}

int CTilemapParser::countWith(const char *tag)
{
    return m_xmlparser.count(tag);
}

void CTilemapParser::parse(int index, TmxTileSet &tileset)
{
    const char* tag = "tileset";
    tileset.name            = m_xmlparser.parseTagWith(index, tag, "name");
    tileset.first_global_id = std::stoi(m_xmlparser.parseTagWith(index, tag, "firstgid"));
    tileset.columns         = std::stoi(m_xmlparser.parseTagWith(index, tag, "columns"));
    tileset.tile_count      = std::stoi(m_xmlparser.parseTagWith(index, tag, "tilecount"));
    tileset.tile_width      = std::stoi(m_xmlparser.parseTagWith(index, tag, "tilewidth"));
    tileset.tile_height     = std::stoi(m_xmlparser.parseTagWith(index, tag, "tileheight"));

    {
        const char* tag = "tileset.image";
        tileset.image           = new TmxImage;
        tileset.image->source   = m_xmlparser.parseTagWith(0, tag, "source");
        tileset.image->width    = std::stoi(m_xmlparser.parseTagWith(index, tag, "width"));
        tileset.image->height   = std::stoi(m_xmlparser.parseTagWith(index, tag, "height"));
    }

    *(m_map.tilesets + index)   = tileset;
}

void CTilemapParser::parse(int index, TmxLayer &layer)
{
    const char* tag = "layer";
    layer.name              = m_xmlparser.parseTagWith(index, tag, "name");;
    layer.width             = std::stoi(m_xmlparser.parseTagWith(index, tag, "width"));
    layer.height            = std::stoi(m_xmlparser.parseTagWith(index, tag, "height"));
    layer.visible           = static_cast<bool>(m_xmlparser.parseTagWith(index, tag, "visible"));

    {
        const char* tag = "layer.data";
        layer.data              = new TmxData;
        layer.data->encoding    = m_xmlparser.parseTagWith(index, tag, "encoding");
        layer.data->content     = m_xmlparser.extractTagContentWith(index, tag);
    }
}
