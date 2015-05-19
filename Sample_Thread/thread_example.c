/**********************************************************
 * Author        : yxmsw2007
 * Email         : yxmsw2007@gmail.com
 * Last modified : 2015-05-19 22:34
 * Filename      : thread_example.c
 * Description   : gcc -lpthread thread_example.c -o thread_example
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define     MAX 3

int number = 0;

pthread_t id[2];

pthread_mutex_t mut; //初始化静态互斥锁

void thread1(void) {
    int i;
    printf("Hello, I am pthread1!\n");
    for (i = 0; i < MAX; i++)
    {
        pthread_mutex_lock(&mut); //此处上锁，保证number的唯一性
        number++;
        printf("THread1: number = %d\n", number);
        pthread_mutex_unlock(&mut);
        sleep(1); //linux c下sleep(minute),里面单位是分钟
    }
    pthread_exit(NULL); //线程通过执行此函数，终止执行。返回是一个空指针类型
}

void thread2(void) {
    int i;
    printf("Hello, I am pthread2!\n");
    for (i = 0; i < MAX; i++)
    {
        pthread_mutex_lock(&mut); //此处上锁，保证number的唯一性
        number++;
        printf("THread2: number = %d\n", number);
        pthread_mutex_unlock(&mut);
        sleep(1); //linux c下sleep(minute),里面单位是分钟
    }
    pthread_exit(NULL); //线程通过执行此函数，终止执行。返回是一个空指针类型
}

void thread_create(void) {
    int temp;
    memset(&id, 0, sizeof(id));
    if (temp = pthread_create(&id[0], NULL, (void*)thread1, NULL) != 0)
    {
       printf("Thread1 fail to create!\n"); 
    } else {
        printf("Thread 1 create!\n");
    }
    if (temp = pthread_create(&id[1], NULL, (void*)thread2, NULL) != 0)
    {
        printf("Thread 2 fail to create!\n");
    } else {
        printf("Thread 2 create!\n");
    }
}

void thread_wait() {
    if (id[0] != 0)
    {
        pthread_join(id[0], NULL);
        printf("Thread 1 completed!\n");
    }
    if (id[1] != 0)
    {
        pthread_join(id[1], NULL);
        printf("Thread 2 completed!\n");
    }
}

int main(int argc, char *argv[])
{
    int i, ret1, ret2;
    pthread_mutex_init(&mut, NULL); //动态互斥锁
    printf("Main function, creating thread...\n");
    thread_create();
    printf("Main function, waiting for the pthread end!\n");
    thread_wait();
    // 代码中如果没有pthread_join主线程会很快结束从而使整个进程结束，从而使创建的线程没有机会开始执行就结束了。
    // 加入pthread_join后，主线程会一直等待直到等待的线程结束自己才结束，使创建的线程有机会执行。
    return (0);
}
