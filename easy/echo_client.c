#include "csapp.h"

int main(int argc, char **argv) {
    int clientfd;
    char *host, *port, buf[MAXLINE];
    rio_t rio;

    host = "localhost";
    port = "80";

    // 建立连接（前面已经详细介绍）
    clientfd = Open_clientfd(host, atoi(port));
    Rio_readinitb(&rio, clientfd);

    //while (Fgets(buf, MAXLINE, stdin) != NULL) {
    strcpy(buf, "*2\r\n$3\r\nGET\r\n$1\r\na");
    Rio_writen(clientfd, buf, strlen(buf));
    memset(buf, 0, MAXLINE);
    strcpy(buf, "\r\n");
    Rio_writen(clientfd, buf, strlen(buf));

    Rio_writen(clientfd, buf, strlen(buf));
    // 读取，也就是从服务器接收信息
    Rio_readlineb(&rio, buf, MAXLINE);
    Fputs(buf, stdout);
    Rio_readlineb(&rio, buf, MAXLINE);
    Fputs(buf, stdout);
    //}
    Close(clientfd);
    exit(0);
}