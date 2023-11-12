#ifndef CTHREADPOOL_H
#define CTHREADPOOL_H

#include <thread>
#include <vector>

class CThreadPool
{
private:
    std::vector<std::thread> m_threads;
public:
    CThreadPool();
};

#endif // CTHREADPOOL_H
