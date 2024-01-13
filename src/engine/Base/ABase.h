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

static std::string identify_type(void* ptr) {
    const char* type = "";
    ABase* obj = static_cast<ABase*>(ptr);
    if(obj != nullptr)
    {
        type = obj->className();
    }
    DBG("Type of [%p] is [%s] with lenght is [%d]", ptr, type, strlen(type))
    return std::string(type);
}

END_NAMESPACE

#endif // ABASE_H
