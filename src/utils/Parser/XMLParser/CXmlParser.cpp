#include "CXmlParser.h"

CXmlParser::CXmlParser()
{

}

bool CXmlParser::loadFile(const char *file)
{
    if(m_document.LoadFile(file))
    {
        m_root = m_document.RootElement();
        for(TiXmlElement *e = m_root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
        {
            m_nodes[e->Value()].emplace_back(e);
        }
        return true;
    }
    return false;
}

const char *CXmlParser::rootAttribute(const char *attribute)
{
    return m_root->Attribute(attribute);
}

