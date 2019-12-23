#include "my.h"

#define SIZE 100

int a [SIZE],b[SIZE];
int max;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void max_fun(int *arg)
{
	int * ap=arg;
	int rv,i,l_max;
	for(i=1;i<SIZE;i++)
	{
		if(ap[i]>l_max)
		l_max = ap[i];
	}
	
	rv = pthread_mutex_lock(&mtx);
	check_error(rv,"mutex_lock");
	if(l_max > max)
		max = l_max;
	rv = pthread_mutex_unlock(&mtx);
	check_error(rv,"mutex_unlock");
	pthread_exit(NULL);
}
