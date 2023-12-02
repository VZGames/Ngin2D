#include "CXmlParser.h"
#include <iostream>

CXmlParser::CXmlParser()
{

}


void CXmlParser::iterateAllTags(TiXmlElement* parent)
{
    for(TiXmlElement* e = parent->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        std::string tag = e->Value();
        if(parent->Value() != m_root->Value())
        {
            tag = std::string(parent->Value()) + "." + std::string(e->Value());
        }
        m_nodes[tag].emplace_back(e);
        iterateAllTags(e);
    }
}

bool CXmlParser::loadFile(const char *file)
{
    if(m_document.LoadFile(file))
    {
        m_root = m_document.RootElement();
        iterateAllTags(m_root);
//        for(auto node: m_nodes)
//        {
//            std::cout << node.first << std::endl;
//        }
        return true;
    }

    return false;
}

const char *CXmlParser::rootAttribute(const char *attribute)
{
    return m_root->Attribute(attribute);
}

int CXmlParser::count(const char *tag)
{
    if(m_nodes.find(tag) == m_nodes.end()) return 0;
    return static_cast<int>(m_nodes[tag].size());
}

const char *CXmlParser::extractTagContentWith(int index, const char *tag)
{
    if(m_nodes.find(tag) == m_nodes.end()) return "Empty";
    return m_nodes[tag].at(index)->GetText();
}

const char* CXmlParser::parseTagWith(int index, const char *tag, const char *attribute)
{
    if(m_nodes.find(tag) == m_nodes.end()) return "Empty";
    return m_nodes[tag].at(index)->Attribute(attribute);
}

