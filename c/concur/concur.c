#include "concur.h"


static pthread_mutex_t thread_pool_lock_;
static pthread_mutex_t dead_lock_;
static pthread_cond_t thread_pool_cond_;
static int is_thread_pool_running = 0;


static void * monitor_thread_entry(void * param)
{
    int timeout = *((int *)param);
    free(param);
    printf("thread pool will be stopped %d seconds later.\n", timeout);
    sleep(timeout);
    printf("sleep finish.\n");
    is_thread_pool_running = 0;
    pthread_mutex_unlock(&dead_lock_);
    return NULL;
}

//  <================    thread entry functions    =================>
static void * thread_pool_entry(void * thread_params)
{
    while(is_thread_pool_running)
    {
        printf("before mutex lock %u\n", (unsigned int)pthread_self());
        pthread_mutex_lock(&thread_pool_lock_);
        printf("after mutex lock %u\n", (unsigned int)pthread_self());

        struct timespec abstime;
        clock_gettime(CLOCK_REALTIME, &abstime);
        int timeout = 10;
        abstime.tv_sec += timeout;

        printf("before timed wait %u\n", (unsigned int)pthread_self());
        int timed_wait_ret = pthread_cond_timedwait(&thread_pool_cond_, &thread_pool_lock_, &abstime);
        if(timed_wait_ret == 0)
        {
            printf("thread: %u was awaken by pthread_cond_signal\n", (unsigned int)pthread_self());
        }
        else if(timed_wait_ret == ETIMEDOUT)
        {
            printf("thread: %u timeout\n", (unsigned int)pthread_self());
        }
        
        pthread_mutex_unlock(&thread_pool_lock_);
    }
    printf("thread %u is going to exit\n", (unsigned int)pthread_self());
    return NULL;
}

static void * thread_pool_entry_2(void * thread_params)
{
    while(is_thread_pool_running)
    {
        printf("before mutex lock\n");
        pthread_mutex_lock(&thread_pool_lock_);
        printf("after mutex lock\n");

        printf("before wait\n");
        pthread_cond_wait(&thread_pool_cond_, &thread_pool_lock_);
        printf("after wait\n");
        pthread_mutex_unlock(&thread_pool_lock_);
    }

    printf("thread_pool_entry_2 of thread %u is going to exit\n", (unsigned int)pthread_self());
    return NULL;
}
// end

//<===================     scenarios of multiple threads    =====================>

/*
 * This scenario is that threads are blocked by pthread_cond_timedwait and pthread_cond_wait
 * The expected phenomenon is that the condition variable will be impacted by pthread_cond_timedwait 
 * and pthread_cond_wait
 */
void test_cond_timedwait_cond_wait_no_signal(int threadNum)
{
    int i = 0;
    for(;i < threadNum; i++)
    {
    	pthread_t thread_id;
    	pthread_create(&thread_id, NULL, thread_pool_entry, NULL);
    	sleep(1);
    }

    pthread_t thread2;
    pthread_create(&thread2, NULL, thread_pool_entry_2, NULL);
}

/*
 * This scenario is that threads are blocked by pthread_cond_timedwait and pthread_cond_wait
 * and main thread will call pthread_cond_signal to awake sleeping thread.
 * The expected phenomenon is that all threads will be awaken no matter it's blocked by pthread_cond_wait
 * or pthread_cond_timedwait
 * pthread_cond_timedwait returns 0 if it's awaken by pthread_cond_signal
 * pthread_cond_timedwait returns ETIMEDOUT if it's timeout.
 */
void test_cond_timedwait_cond_wait_has_signal(int threadNum)
{
    int i = 0;
    for(;i < threadNum; i++)
    {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread_pool_entry, NULL);
        sleep(1);
    }

    pthread_t thread2;
    pthread_create(&thread2, NULL, thread_pool_entry_2, NULL);

    int flag = 1;
    while(flag)
    {
        sleep(3);
        pthread_cond_signal(&thread_pool_cond_);
    }
}
// end

void set_timeout_to_thread_pool(int timeout)
{
    pthread_t monitor_thread;
    int * t = malloc(sizeof(int));
    *t = timeout;
    pthread_create(&monitor_thread, NULL, monitor_thread_entry, t);
}

void deadlock()
{
    pthread_mutex_lock(&dead_lock_);
    pthread_mutex_lock(&dead_lock_);
}

int initialize_cond_mutex()
{
    int thread_pool_lock_init_ret = pthread_mutex_init(&thread_pool_lock_, NULL);
    if(thread_pool_lock_init_ret)
    {
        return thread_pool_lock_init_ret;
    }

    int thread_pool_cond_init_ret = pthread_cond_init(&thread_pool_cond_, NULL);
    if(thread_pool_cond_init_ret)
    {
        return thread_pool_cond_init_ret;
    }

    int dead_lock_init_ret = pthread_mutex_init(&dead_lock_, NULL);
    if(dead_lock_init_ret)
    {
        return dead_lock_init_ret;
    }

    is_thread_pool_running = 1;
    return 0;
}

void release_mutex_cond()
{
    pthread_mutex_destroy(&thread_pool_lock_);
    pthread_mutex_destroy(&dead_lock_);
    pthread_cond_destroy(&thread_pool_cond_);
}

void stopThreadPool()
{
    is_thread_pool_running = 0;
}

void startThreadPool()
{
    is_thread_pool_running = 1;
}

void signal_cond()
{
    pthread_cond_signal(&thread_pool_cond_);
}