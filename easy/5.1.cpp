#include <stdio.h>
#include <unistd.h>
#include <csignal>

void sigint_handler(int sig) // SIGINT 处理器
{
    printf("想通过 ctrl+c 来关闭我？\n");
    sleep(2);
    fflush(stdout);
    sleep(1);
    printf("OK. :-)\n");
    _exit(0);
}

int main()
{
    // 设定 SIGINT 处理器
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
        perror("signal error");

    // 等待接收信号
    pause();
    return 0;
}
