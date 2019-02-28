#include <concur/concur.h>
#include <concur/prod_cons.h>

static void task_handler_1(void * param)
{
    int val = *(int *)param;
    printf("This is int %d\n", val);
}

static void task_handler_2(void * param)
{
    char * str = (char *)param;
    printf("This is a string: %s\n", str);
}

static void task_handler_3(void * param)
{
    printf("do nothing\n");
}

static void * insert_task_thread_entry(void * param)
{
    Task * task = (Task *)param;
    TaskNode * task_node = (TaskNode *)malloc(sizeof(TaskNode));
    task_node->task_ = task;
    task_node->next_task_ = NULL;
    insertTask(task_node);
    return NULL;
}

static void * monitor_entry(void * param)
{
    do
    {
        sleep(15);
    }while(!taskQueueEmpty());
    stop_threads();
    broad_cast();
    sleep(2);
    unlock_deadlock();
    return NULL;
}

static void do_async_insert_tasks()
{
    const int task_count = 3;
    int param_1 = 10;
    char * param_2 = "string parameter for task 2";
    Task test_task_array[3] = {
        {
            task_handler_1,
            &param_1
        },
        {
            task_handler_2,
            param_2
        },
        {
            task_handler_3,
            &param_1
        }
    };

    int i;
    for(i = 0; i < task_count; ++i)
    {
        pthread_t insert_task_tid;
        pthread_create(&insert_task_tid, NULL, insert_task_thread_entry, &test_task_array[i]);
        sleep(1);
    }
}

int main(int argc, char ** argv)
{
    printf("start time: %u\n", (unsigned int)time(NULL));
    int init_ret = initialize_cond_mutex();
    if(init_ret)
    {
        return init_ret;
    }

    set_timeout_to_thread_pool(120);

    printf("=====    test_cond_timedwait_cond_wait_no_signal  ====\n");
    test_cond_timedwait_cond_wait_no_signal(3);
    sleep(15);
    printf("test_cond_timedwait_cond_wait_no_signal finished time: %u\n", (unsigned int)time(NULL));
    stopThreadPool();
    sleep(3);
    signal_cond();
    sleep(3);

    printf("\n\n=====    test_cond_timedwait_cond_wait_has_signal  ====\n");
    startThreadPool();
    test_cond_timedwait_cond_wait_has_signal(3);
    sleep(30);
    stopThreadPool();
    sleep(5);
    signal_cond();
    sleep(3);
    release_mutex_cond();

    printf("\n\n=====    test producer consumer model  ====\n");
    startProducerConsumerModel(4);
    sleep(3);
    do_async_insert_tasks();
    pthread_t monitor_tid;
    pthread_create(&monitor_tid, NULL, monitor_entry, NULL);
    do_deadlock();
    printf("Test finished.\n");
    return 0;
}