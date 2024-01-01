#ifndef CTHREAD_WORKER_H
#define CTHREAD_WORKER_H

#include <functional>
#include <mutex>
#include <queue>

class CThreadPool;
class CThreadWorker
{
private:
    CThreadPool                     *m_pool;
    int                             m_id;
public:
    CThreadWorker(CThreadPool *pool, int id);

    void operator()();
};


#endif // CTHREAD_WORKER_H
