#include "CThreadPool.h"
#include "CThreadWorker.h"

CThreadPool::CThreadPool(const int &n_threads)
:m_threads(std::vector<std::thread>(n_threads))
{

}

void CThreadPool::init()
{
    for(int i = 0; i < static_cast<int>(m_threads.size()); i++)
    {
        m_threads[i] = std::thread(CThreadWorker(this, i));
    }
}

void CThreadPool::shutdown()
{
    m_shutdown = true;
    m_conditional_lock.notify_all();

    for (int i = 0; i < static_cast<int>(m_threads.size()); ++i) {
        if(m_threads[i].joinable()) {
            m_threads[i].join();
        }
    }
}
