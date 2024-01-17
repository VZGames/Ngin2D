#ifndef CENTITY_H
#define CENTITY_H

#include <LoggerDefines.h>
#include <CommonDefine.h>
#include "ABase.h"
#include "Alias.h"
#include "Component/CComponent.h"
#include "Component/CComponentManager.h"

#define COMP_MANAGER CComponentManager::instance()

BEGIN_NAMESPACE(engine)
class CEntity: public ABase
{
private:
    EntityID                                         m_id;
    std::unordered_map<const char*, CComponent*>     m_components;

protected:
    std::mutex                                       m_mutex;

public:
    CEntity();
    virtual ~CEntity(); 

    bool operator==(const CEntity &other) { return this->id() == other.id(); }
    bool operator==(const CEntity *other) { return this->id() == other->id(); }

    EntityID id() const;
    void setId(const EntityID &newId);

    template<class T, typename ...TArgs>
    T *addComponent(TArgs&&...args)
    {
        const char *compName = typeid(T).name();
        assert(m_components.find(compName) == m_components.end() && "Adding component more than once.");

        T *c = new T(std::forward<TArgs>(args)...);
        COMP_MANAGER->createComponent(c);
        m_components[compName] = std::move(c);
        return static_cast<T*>(m_components.at(compName));
    }

    template<class T>
    bool destroyComponent()
    {
        const char *compName = typeid(T).name();
        auto it = m_components.find(compName);
        if(it == m_components.end())
            return 0;
        m_components.erase(it);
        return 1;
    }

    template<class T>
    T* getComponent() const
    {
        const char *compName = typeid(T).name();
        DBG("1 ")
        if(m_components.empty()) return nullptr;
        DBG("2 ")
        if(m_components.find(compName) == m_components.end())
        {
            DBG("Component [%s] does not exist", compName);
            return nullptr;
        }
        DBG("3 %p %s", this, compName)
        return static_cast<T*>(m_components.at(compName));
    }

    template<class T>
    bool hasComponent() const
    {
        const char *compName = typeid(T).name();
        if(m_components.find(compName) == m_components.end()) return false;
        if(m_components.at(compName) == nullptr)
        {
            return false;
        }
        return true;
    }

};
END_NAMESPACE

#endif // CENTITY_H
