#ifndef CONCUR_H
#define CONCUR_H

#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


void test_cond_timedwait_cond_wait_no_signal(int threadNum);
void test_cond_timedwait_cond_wait_has_signal(int threadNum);

void set_timeout_to_thread_pool(int timeout);
int initialize_cond_mutex();
void release_mutex_cond();
void deadlock();
void stopThreadPool();
void startThreadPool();
void signal_cond();

#endif