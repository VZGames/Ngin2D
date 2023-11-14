#ifndef CTHREADPOOL_H
#define CTHREADPOOL_H

#include <condition_variable>
#include <functional>
#include <thread>
#include <vector>
#include <future>
#include "CSafeQueue.h"

class CThreadWorker;
class CThreadPool
{
private:
    friend class CThreadWorker;
    std::vector<std::thread>                    m_threads;
    CSafeQueue<std::function<void()>>           m_queue;
    std::mutex                                  m_conditional_mutex;
    std::condition_variable                     m_conditional_lock;
    bool                                        m_shutdown{false};
public:
    CThreadPool(const int &n_threads);

    CThreadPool(const CThreadPool &) = delete;
    CThreadPool(CThreadPool &&) = delete;

    CThreadPool & operator=(const CThreadPool &) = delete;
    CThreadPool & operator=(CThreadPool &&) = delete;

    // Inits thread pool
    void init();

    // Waits until threads finish their current task and shutdowns the pool
    void shutdown();

    // Submit a function to be executed asynchronously by the pool
    template<typename Fn, typename ...TArgs>
    auto submit(Fn&& fn, TArgs&&... args) -> std::future<decltype(fn(args...))>
    {
        // Create a function with bounded parameters ready to execute
        std::function<decltype(fn(args...))()> func = std::bind(std::forward<Fn>(fn), std::forward<TArgs>(args)...);
        // Encapsulate it into a shared ptr in order to be able to copy construct / assign
        auto task_ptr = std::make_shared<std::packaged_task<decltype(fn(args...))()>>(func);

        // Wrap packaged task into void function
        std::function<void()> wrapper_func = [task_ptr]() {
            (*task_ptr)();
        };

        // Enqueue generic wrapper function
        m_queue.enqueue(wrapper_func);

        // Wake up one thread if its waiting
        m_conditional_lock.notify_one();

        // Return future from promise
        return task_ptr->get_future();
    }
};

#endif // CTHREADPOOL_H
