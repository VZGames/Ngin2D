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

inline const char *identify_type(ABase *obj) noexcept
{
    if(obj != nullptr)
    {
        return obj->className();
    }
    return "";
}

END_NAMESPACE

#endif // ABASE_H
