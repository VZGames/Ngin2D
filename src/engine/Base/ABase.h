#ifndef ABASE_H
#define ABASE_H

#include <CommonDefine.h>
#include <LoggerDefines.h>

BEGIN_NAMESPACE(engine)
class ABase
{
protected:
    const char* m_class_name;

public:
    const char* className() const
    {
        return m_class_name;
    }
};

static std::string identify_type(const void* ptr) {
    const char* type = "_";
    const ABase* obj = static_cast<const ABase*>(ptr);
    if(obj != nullptr)
    {
        type = obj->className();
    }
    DBG("Type of [%p] is [%s]", ptr, type)
    return std::string(type);
}

END_NAMESPACE

#endif // ABASE_H
