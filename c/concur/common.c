#include "common.h"

static pthread_mutex_t mul_thread_lock_;
static pthread_mutex_t dead_lock_;
static pthread_cond_t mul_thread_cond_;
static int is_running = 0;


int initialize_resources()
{
    is_running = 1;

    int thread_pool_lock_init_ret = pthread_mutex_init(&mul_thread_lock_, NULL);
    if(thread_pool_lock_init_ret)
    {
        return thread_pool_lock_init_ret;
    }

    int thread_pool_cond_init_ret = pthread_cond_init(&mul_thread_cond_, NULL);
    if(thread_pool_cond_init_ret)
    {
        return thread_pool_cond_init_ret;
    }

    int dead_lock_init_ret = pthread_mutex_init(&dead_lock_, NULL);
    if(dead_lock_init_ret)
    {
        return dead_lock_init_ret;
    }
    return 0;
}

void release_resources()
{
    pthread_mutex_destroy(&mul_thread_lock_);
    pthread_mutex_destroy(&dead_lock_);
    pthread_cond_destroy(&mul_thread_cond_);
    is_running = 0;
}

int is_threads_running()
{
    return is_running;
}

void stop_threads()
{
    is_running = 0;
}

void do_deadlock()
{
    pthread_mutex_lock(&dead_lock_);
    pthread_mutex_lock(&dead_lock_);
}

void unlock_deadlock()
{
    pthread_mutex_unlock(&dead_lock_);
}

void lock_mul_thread_lock()
{
    pthread_mutex_lock(&mul_thread_lock_);
}

void unlock_mul_thread_lock()
{
    pthread_mutex_unlock(&mul_thread_lock_);
}

void wait()
{
    pthread_cond_wait(&mul_thread_cond_, &mul_thread_lock_);
}

void signal()
{
    pthread_cond_signal(&mul_thread_cond_);
}

void broad_cast()
{
    pthread_cond_broadcast(&mul_thread_cond_);
}