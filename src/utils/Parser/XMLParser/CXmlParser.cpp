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
            m_nodes[e->Value()] = e;
        }
        return true;
    }
    return false;
}

bool CXmlParser::parse(const char *tag)
{

    m_nodes.at(tag);
    return false;
}

const char *CXmlParser::rootAttribute(const char *attribute)
{
    return m_root->Attribute(attribute);
}

