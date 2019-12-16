 #include "mylib.h"

#define UNUMBER 100

int main()
{
	int a[UNUMBER];
	init(a,UNUMBER);
	show(a,UNUMBER);	  
    printf("sum=%d\n,max=%d\n",sum(a,UNUMBER),max(a,UNUMBER));
	return 0;
}
