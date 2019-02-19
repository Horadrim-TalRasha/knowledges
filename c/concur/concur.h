#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef  void* (*thread_func)(void *);

typedef  void* (*task_handler)(void *);

typedef struct Task
{
    task_handler * handler_;
    void * parameters_;
} Task;

typedef struct TaskNode
{
    Task * task_;
    struct TaskNode * next_task_;
} TaskNode;

typedef struct TaskQueue
{
    TaskNode task_head_node_;
} TaskQueue;

void test_cond_timedwait_cond_wait_no_signal(int threadNum);
void test_cond_timedwait_cond_wait_has_signal(int threadNum);

void set_timeout_to_thread_pool(int timeout);
int initialize_cond_mutex();
void release_mutex_cond();
void deadlock();
void stopThreadPool();
void startThreadPool();
void signal_cond();