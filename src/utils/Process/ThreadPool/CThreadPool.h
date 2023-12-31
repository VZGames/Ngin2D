#ifndef CTHREAD_POOL_H
#define CTHREAD_POOL_H

#include <condition_variable>
#include <functional>
#include <thread>
#include <vector>
#include <future>
#include <type_traits>
#include <assert.h>
#include "../CSafeQueue.h"

class CThreadWorker;
class CThreadPool
{
private:
    friend class CThreadWorker;
    std::vector<std::thread> m_threads;
    CSafeQueue<std::function<void()>> m_queue;
    std::mutex m_queue_mutex;
    std::condition_variable m_conditional_lock;
    bool m_shutdown{false};

public:
    CThreadPool(const int &n_threads);

    CThreadPool(const CThreadPool &) = delete;
    CThreadPool(CThreadPool &&) = delete;

    CThreadPool &operator=(const CThreadPool &) = delete;
    CThreadPool &operator=(CThreadPool &&) = delete;

    // Inits thread pool
    void init();

    // Waits until threads finish their current task and shutdowns the pool
    void shutdown();

    // Submit a function to be executed asynchronously by the pool
    template <typename _Func, typename... _Args>
    std::future<std::invoke_result_t<_Func, _Args...>> submit(_Func &&fn, _Args &&...args)
    {
        /* The return type of task `F` */
        using return_type = std::invoke_result_t<_Func, _Args...>;

        /* wrapper for no arguments */
        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<_Func>(fn), std::forward<_Args>(args)...));

        
        assert(task != nullptr && "Task is NULL!!!");

        // Wrap packaged task into void function
        std::function<void()> wrapper_func = [task]()
        {
            (*task)();
        };

        // Enqueue generic wrapper function
        m_queue.enqueue(wrapper_func);

        // Wake up one thread if its waiting
        m_conditional_lock.notify_one();

        // Return future from promise
        return task->get_future();
    }

    #define WRAP_SUBMIT(FUNC) submit<decltype(&FUNC), &FUNC>

};

#endif // CTHREAD_POOL_H
