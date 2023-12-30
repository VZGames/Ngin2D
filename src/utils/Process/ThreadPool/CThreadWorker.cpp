#include "CThreadWorker.h"
#include "CThreadPool.h"

CThreadWorker::CThreadWorker(CThreadPool *pool, int id)
    :m_pool(pool), m_id(id)
{

}

void CThreadWorker::operator()()
{
    std::function<void()> func;
    bool dequeued;
    while (!m_pool->m_shutdown) {
        {
            std::unique_lock<std::mutex> lock(m_pool->m_queue_mutex);
            if (m_pool->m_queue.empty()) {
                m_pool->m_conditional_lock.wait(lock);
            }
            dequeued = m_pool->m_queue.dequeue(func);
        }
        if (dequeued) {
            func();
        }
    }
}
