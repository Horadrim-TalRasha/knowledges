#ifndef COMMON_H
#define COMMON_H

#include <pthread.h>

int initialize_resources();
void release_resources();
int is_threads_running();
void stop_threads();
void do_deadlock();
void unlock_deadlock();
void lock_mul_thread_lock();
void unlock_mul_thread_lock();
void wait();
void signal();
void broad_cast();

#endif