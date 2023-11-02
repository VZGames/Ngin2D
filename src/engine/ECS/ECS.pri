HEADERS += \
    $$PWD/Component/CComponent.h \
    $$PWD/Component/CComponentManager.h \
    $$PWD/Component/ComponentDef/SCameraComponent.h \
    $$PWD/Component/ComponentDef/SHealthComponent.h \
    $$PWD/Component/ComponentDef/SPositionComponent.h \
    $$PWD/Component/ComponentDef/SSpriteComponent.h \
    $$PWD/Entity/CEntity.h \
    $$PWD/Entity/CEntityManager.h \
    $$PWD/Systems/CECSystemManager.h \
    $$PWD/Systems/CollisionSystem/CCollisionSystem.h \
    $$PWD/Systems/IECSystem.h \
    $$PWD/Systems/MovementSystem/CMovementSystem.h \
    $$PWD/Systems/RenderSystem/CRenderSystem.h

SOURCES += \
    $$PWD/Component/CComponent.cpp \
    $$PWD/Component/CComponentManager.cpp \
    $$PWD/Entity/CEntity.cpp \
    $$PWD/Entity/CEntityManager.cpp \
    $$PWD/Systems/CECSystemManager.cpp \
    $$PWD/Systems/CollisionSystem/CCollisionSystem.cpp \
    $$PWD/Systems/MovementSystem/CMovementSystem.cpp \
    $$PWD/Systems/RenderSystem/CRenderSystem.cpp


INCLUDEPATH += \
    $$PWD/Component \
    $$PWD/Entity \
    $$PWD/Systems \
    $$PWD
