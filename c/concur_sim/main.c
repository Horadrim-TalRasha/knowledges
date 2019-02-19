#include <concur/concur.h>

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
    sleep(10);
    signal_cond();
    printf("awaken thread_pool_entry_2\n");
    sleep(3);
    printf("=====    test_cond_timedwait_cond_wait_has_signal  ====\n");
    startThreadPool();
    test_cond_timedwait_cond_wait_has_signal(3);
    deadlock();
    release_mutex_cond();
    
    printf("Test finished.\n");
    return 0;
}