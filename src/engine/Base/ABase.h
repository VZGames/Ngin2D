#ifndef ABASE_H
#define ABASE_H

#include <CommonDefine.h>

BEGIN_NAMESPACE(engine)
class ABase
{
protected:
    const char* m_derived_class_name;

public:
    const char* derived_class_name() const
    {
        return m_derived_class_name;
    }
};

inline const char* identify_type(const void* ptr) {
    const ABase* obj = static_cast<const ABase*>(ptr);
    return obj->derived_class_name();
}

END_NAMESPACE

#endif // ABASE_H
