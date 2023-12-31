#ifndef CNGIN_H
#define CNGIN_H

#include <CommonDefine.h>
#include "Alias.h"
#include "size2D.h"
#include "ThreadPool/CThreadPool.h"

BEGIN_NAMESPACE(engine)
class CWorld;
class CNgin
{
private:
    CNgin();
    ~CNgin();
    static bool s_running;
    static CNgin *s_instance;
    static uint32_t s_win_width;
    static uint32_t s_win_height;
    CWorld *m_world;
    static std::mutex s_mutex;

    CThreadPool m_key_evt_pool;

public:
    static CNgin *instance();
    static bool running();
    static void setRunning(bool);
    static Size2D<float> windowSize();

public:
    bool initialize(_Title, _Width, _Height, CWorld *);
    void loop();
    void clean();
    void quit();

private:
    void render();
    void update(float);
    void handle_events();
};
END_NAMESPACE

#endif // CNGIN_H
