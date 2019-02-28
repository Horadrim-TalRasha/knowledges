#ifndef Prod_Cons_H
#define Prod_Cons_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "common.h"

typedef  void* (*thread_func)(void *);

typedef  void (*task_handler)(void *);

typedef struct Task
{
    task_handler handler_;
    void * parameters_;
} Task;

typedef struct TaskNode
{
    Task * task_;
    struct TaskNode * next_task_;
} TaskNode;

typedef struct TaskQueue
{
    TaskNode * task_head_node_;
} TaskQueue;


void insertTask(TaskNode * task);
int startProducerConsumerModel(int prod_thread_num);
int taskQueueEmpty();

#endif