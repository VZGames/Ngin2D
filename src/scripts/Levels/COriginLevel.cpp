#include "COriginLevel.h"

BEGIN_NAMESPACE(script)
COriginLevel::COriginLevel()
{
    m_name = __FUNCTION__;
    m_parser.loadFile("./debug/assets/Maps/PhuHoa.tmx");
}

void COriginLevel::update(float)
{

}

void COriginLevel::render()
{

}
END_NAMESPACE

