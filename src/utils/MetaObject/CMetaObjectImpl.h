#ifndef __C_META_OBJECTIMPL_H__
#define __C_META_OBJECTIMPL_H__

#include "CMetaObject.h"
#include <typeinfo>

template<typename T>
class CMetaObjectImpl: public CMetaObject
{
public:
    virtual const char* className() const override
    {
        return typeid(T).name();
    }
};

// Function to retrieve a metaobject for a given type
template <typename T>
CMetaObject *getMetaObject()
{
    static CMetaObjectImpl<T> metaObject;
    return &metaObject;
}

#endif // __C_META_OBJECTIMPL_H__