#include "csapp.h"

/**
 * cnt 使用了 volatile 关键字声明，意思是不要在寄存器中保存值，无论是读取还是写入，都要对内存操作
 */
volatile long cnt = 0;

void *thread(void *vargp)
{
    long *niters = (long*)vargp;
    printf("thread: %ld\n", *niters);
    for (int i = 0; i < *niters; i++)
        cnt++;
    return NULL;
}

int main(int argc, char **argv)
{
    long niters;
    pthread_t tid1, tid2;

    niters = 90000;
    Pthread_create(&tid1, NULL, thread, &niters);
    Pthread_create(&tid2, NULL, thread, &niters);
    Pthread_join(tid1, NULL);
    Pthread_join(tid2, NULL);
    printf("main thread\n");

    // 检查结果
    if (cnt != (2 * niters))
        printf("Wrong! cnt=%ld\n", cnt);
    else
        printf("Correct! cnt=%ld\n", cnt);
    exit(0);
}