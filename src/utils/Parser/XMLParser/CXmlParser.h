#ifndef CXMLPARSER_H
#define CXMLPARSER_H

#include <map>
#include <vector>
#include <TinyXML2/tinyxml.h>

class CXmlParser
{
private:
    TiXmlElement                                        *m_root;
    TiXmlDocument                                       m_document;
    std::map<const char*,std::vector<TiXmlElement*>>    m_nodes;

public:
    CXmlParser();
    bool loadFile(const char* file);
    const char* rootAttribute(const char* attribute);
};

#endif // CXMLPARSER_H
