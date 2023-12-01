#include "CLevelSys.h"

BEGIN_NAMESPACE(engine)
CLevelSys *CLevelSys::s_instance = nullptr;
CLevelSys::CLevelSys()
{

}

CLevelSys *CLevelSys::instance()
{
    return s_instance = (s_instance == nullptr)? new CLevelSys(): s_instance;
}

void CLevelSys::update(float dt)
{

}
END_NAMESPACE



