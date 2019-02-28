#include "prod_cons.h"

static TaskQueue default_task_queue;


// static void * monitorEntry(void * params)
// {
//     return NULL;
// }

static void * prodEntry(void * params)
{
    
    while(is_threads_running())
    {
        lock_mul_thread_lock();
        while(default_task_queue.task_head_node_ == NULL && is_threads_running())
        {
            wait();
        }

        if(default_task_queue.task_head_node_ != NULL)
        {
            TaskNode * incoming_task = default_task_queue.task_head_node_;
            default_task_queue.task_head_node_ = incoming_task->next_task_;
            printf("incoming_task->next_task_: %p\n", incoming_task->next_task_);
            incoming_task->task_->handler_(incoming_task->task_->parameters_);
        }
        
        unlock_mul_thread_lock();
    }
    
    printf("working thread exit.\n");
    return NULL;
}

void insertTask(TaskNode * task)
{
    lock_mul_thread_lock();
    TaskNode * head = default_task_queue.task_head_node_;
    task->next_task_ = head;
    default_task_queue.task_head_node_ = task;
    signal();
    unlock_mul_thread_lock();
}

int startProducerConsumerModel(int prod_thread_num)
{
    default_task_queue.task_head_node_ = NULL;
    int resource_initialization_ret = initialize_resources();
    if(resource_initialization_ret)
    {
        return resource_initialization_ret;
    }

    int i = 0;
    for(; i < prod_thread_num; ++i)
    {
        pthread_t tid;
        pthread_create(&tid, NULL, prodEntry, NULL);
    }

    return 0;
}

int taskQueueEmpty()
{
    lock_mul_thread_lock();
    int task_queue_empty = (default_task_queue.task_head_node_ == NULL);
    unlock_mul_thread_lock();
    printf("task_queue_empty = %d\n", task_queue_empty);
    return task_queue_empty;
}