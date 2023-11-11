HEADERS += \
    $$PWD/Component/CComponent.h \
    $$PWD/Component/CComponentManager.h \
    $$PWD/Component/ComponentDef/SBodyComponent.h \
    $$PWD/Component/ComponentDef/SBox2DComponent.h \
    $$PWD/Component/ComponentDef/SCameraComponent.h \
    $$PWD/Component/ComponentDef/SHealthComponent.h \
    $$PWD/Component/ComponentDef/SKeyInputComponent.h \
    $$PWD/Component/ComponentDef/SMotionComponent.h \
    $$PWD/Component/ComponentDef/SPositionComponent.h \
    $$PWD/Component/ComponentDef/SSpriteComponent.h \
    $$PWD/Entity/CEntity.h \
    $$PWD/Entity/CEntityManager.h \
    $$PWD/Systems/AECSystem.h \
    $$PWD/Systems/CECSystemManager.h \
    $$PWD/Systems/CameraSystem/CCameraSystem.h \
    $$PWD/Systems/CollisionSystem/CCollisionSystem.h \
    $$PWD/Systems/KeyInputSystem/CKeyInputSystem.h \
    $$PWD/Systems/MovementSystem/CMovementSystem.h \
    $$PWD/Systems/SpriteSystem/CSpriteSystem.h

SOURCES += \
    $$PWD/Component/CComponent.cpp \
    $$PWD/Component/CComponentManager.cpp \
    $$PWD/Entity/CEntity.cpp \
    $$PWD/Entity/CEntityManager.cpp \
    $$PWD/Systems/CECSystemManager.cpp \
    $$PWD/Systems/CameraSystem/CCameraSystem.cpp \
    $$PWD/Systems/CollisionSystem/CCollisionSystem.cpp \
    $$PWD/Systems/KeyInputSystem/CKeyInputSystem.cpp \
    $$PWD/Systems/MovementSystem/CMovementSystem.cpp \
    $$PWD/Systems/SpriteSystem/CSpriteSystem.cpp


INCLUDEPATH += \
    $$PWD/Component \
    $$PWD/Entity \
    $$PWD/Systems \
    $$PWD
