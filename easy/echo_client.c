#include "csapp.h"

int main(int argc, char **argv) {
    int clientfd;
    char *host, *port, buf[MAXLINE];
    rio_t rio;

    host = "127.0.0.1";
    port = "12102";

    // 建立连接（前面已经详细介绍）
    clientfd = Open_clientfd(host, atoi(port));
    Rio_readinitb(&rio, clientfd);

    while (Fgets(buf, MAXLINE, stdin) != NULL) {
        // 写入，也就是向服务器发送信息
        Rio_writen(clientfd, buf, strlen(buf));
        // 读取，也就是从服务器接收信息
        Rio_readlineb(&rio, buf, MAXLINE);
        // 把从服务器接收的信息显示在输出中
        Fputs(buf, stdout);
    }
    Close(clientfd);
    exit(0);
}