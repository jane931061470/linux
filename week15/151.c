#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <stdlib.h>
 
pthread_mutex_t counter_clock=PTHREAD_MUTEX_INITIALIZER;
 
 
int main(int ac,char *av[])
{
  void *count_words(void *);
  if(ac!=3)
  {
    printf("Usage:%s file1 file2\n",av[0]);
    exit(1);
  }
 
 
  pthread_t tidp1,tidp2;
  int error1,error2;
  error1=pthread_create(&tidp1,NULL,count_words,av[1]);
  error2=pthread_create(&tidp2,NULL,count_words,av[2]);
  pthread_join(tidp1,NULL);
  pthread_join(tidp2,NULL);
  return 0;
}
 
void *count_words(void *f)
{
  char *filename=(char *)f;
  FILE *fp;
  int c,prevc='\0';
  int total_words=0;
 
  if((fp=fopen(filename,"r"))!=NULL){
    while((c=getc(fp))!=EOF)
    {
      if(!isalnum(c) && isalnum(prevc)){
         pthread_mutex_lock(&counter_clock);
         total_words++;
         pthread_mutex_unlock(&counter_clock);
       } 
       prevc=c;
    }
    fclose(fp);
    printf("total_words=%d\n",total_words);
  }else{
        perror(filename);
  }
  return NULL;
}
