#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
int maxsize=10;
pthread_t prod,cons;
int in=0,out=0;
int buffer[10];
sem_t sem_s,sem_n;
pthread_mutex_t work_mutex;
void* producer();
void* consumer();
int append();
int take();
void* th_res;
void main()
{
void* th_res;
int res;
res=pthread_mutex_init(&work_mutex,0);
res=sem_init(&sem_s,0,maxsize);
res=sem_init(&sem_n,0,0);
res=pthread_create(&prod,NULL,producer,NULL);
res=pthread_create(&cons,NULL,consumer,NULL);
res=pthread_join(prod,&th_res);
res=pthread_join(cons,&th_res);
}
void* producer()
{ int item;
while(1)
{
sleep(1);
sem_wait(&sem_s);
pthread_mutex_lock(&work_mutex);
printf("Enter item to produce \n");
scanf("%d",&item);
append(item);
pthread_mutex_unlock(&work_mutex);
sem_post(&sem_n);
if(item==999)
break;
}
}
int append(int item)
{
buffer[in]=item;
in=(in+1)%maxsize;
}
void* consumer()
{
int item;
while(1)
{
sleep(1);
sem_wait(&sem_n);
pthread_mutex_lock(&work_mutex);
item= take();
printf("item to be consumed %d\n",item);
pthread_mutex_unlock(&work_mutex);
sem_post(&sem_s);
if(item==999)
break;
}
}
int take()
{
int item=buffer[out];
out=(out+1)%maxsize;
return item;
}
