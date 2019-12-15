#include "my.h"

int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		perror("fork failed!\n");
		exit (-1);
	}
	else if(pid==0)
	{
		printf("child is runing!\n");
		_exit(12);
	}
	else
	{
		//wait(NULL);
		printf("parent is runing!\n");
		return 0;
	}
}
