#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#define MAX 5

void *ran(void* param)
{
    int data = rand() % 10;
    
    return (void *) data;
}

//Driver code
int main()
{

srand(time(0));
    pthread_t threads[5];
    int value[5]={0};
    int data =0;
     printf("error1\n");
    for (size_t i = 0; i < 5; i++)
    {

        data = rand() % 10;
       pthread_create(&threads[i],NULL, ran,(void*)i);
       
    }
int sum =0;
printf("error2\n");
    for (int i = 0; i < 5; i++)
    {
         pthread_join( threads[i], (void**)&value[i] );
         sum+=value[i];
    }
    printf("error3\n");
    printf("The Sum = %d",sum);
  return 0;
}

