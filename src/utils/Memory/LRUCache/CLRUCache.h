#ifndef CLRUCACHE_H
#define CLRUCACHE_H

#include <unordered_map>
#include <list>
#include <CommonDefine.h>
#include <CommonEnums.h>

BEGIN_NAMESPACE(engine)
template<class T>
class CLRUCache
{
public:
    CLRUCache();
    ~CLRUCache();
    E_CACHE_STATUS status() const;
    T* get(uint32_t);
    void put(uint32_t, T*);

private:
    uint32_t                                    m_maxSize{5};
    std::unordered_map<uint32_t, std::list<T*>> m_map;
    std::list<T*>                               m_cache;
};
END_NAMESPACE

#endif // CLRUCACHE_H
