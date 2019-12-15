#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	pid_t pid;
	FILE* fp;
	int i = 0,j = 0;
	if((fp=fopen("test.dat", "w+"))==NULL){
		perror("failed to fopen!\n");
		return -1;
	}
	pid = vfork();
	if(pid<0){
		perror("fork failed\n");
		exit(-1);
	}else if(pid == 0){
		printf("child:pid=%d,finish\n", getpid());
		for(i=0;i<10;i++){
			fprintf(fp,"child:%d\n",i);
		}
		return 0;
	}else{
		printf("parent:pid=%d,finish\n", getpid());
		for(j=0;j<10;j++){
			fprintf(fp,"parent:%d\n",j);
		}
	}
	fclose(fp);
	return 0;
}
