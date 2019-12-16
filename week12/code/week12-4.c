#include "my.h"

#define MSG "OMG,I catch the signal SIGINT\n"
#define MSG_END "OK,finished process signal SIGINT"

int do_heavy_work()
{
	int i;
	int k;
	srand(time(NULL));
	for(i=0;i<1000000000;i++)
	{
		k=rand()%123456789;
	}
	return 0;
}

void signal_handler(int signo)
{
	write(2,MSG,strlen(MSG));
	do_heavy_work();
	write(2,MSG_END,strlen(MSG_END));
}

int main()
{
	
}

