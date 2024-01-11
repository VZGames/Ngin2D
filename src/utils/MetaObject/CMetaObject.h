#ifndef __C_METAOBJECT_H__
#define __C_METAOBJECT_H__

class CMetaObject 
{
public:
    virtual const char* className() const = 0;
};

#endif // __C_METAOBJECT_H__