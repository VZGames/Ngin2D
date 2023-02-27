#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

namespace ngin2D {
class SystemManager
{
public:
    static SystemManager *instance();
private:
    SystemManager();
    static SystemManager *s_instance;
};
}

#endif // SYSTEMMANAGER_H
