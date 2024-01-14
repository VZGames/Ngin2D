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

    static const char *identify_type(void *ptr)
    {
        ABase* obj = static_cast<ABase*>(ptr);
        if(obj != nullptr)
        {
            DBG("%p %p", ptr, obj)
            return obj->className();
        }
        return "";
    }
};

END_NAMESPACE

#endif // ABASE_H
