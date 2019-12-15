#include "my.h"

int main()
{
	int ret;
	printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
	execl("/home/rlk/week9/test1","./test1","123","456",NULL);
	printf("after calling!\n");
	sleep(1);
	return 0;
}
