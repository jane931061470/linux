# include "my.h"

int main()
{
	int ret;
	printf("caller1:pid=%d,ppid=%d\n",getpid(),geyppid());
	ret = system("/home/rlk/week9/test1");
	printf("after calling!\n");
	sleep(100);
	return 0;
}
