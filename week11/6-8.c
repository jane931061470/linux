#include <stdio.h>
#include <time.h>

void init_deamon(void);

int main()
{
	FILE *fp;
	time_t t;
	init_deamon();
	while(1)
	{
		sleep(10);
		if((fp=fopen("6-8.log","a"))>=0)
		{
			t=time(0);
			fprintf(fp,"shouhujinchenghaizaiyunxing,shijianshi: %s",actime(localtime(&t)));
			fclose(fp);
		}
	}
}
