#include "csapp.h"

int main(int argc, char **argv) {
    int n;
    rio_t rio;
    char buf[MAXLINE];

    int fd = Open("test.txt", O_RDONLY, NULL);
    Rio_readinitb(&rio, fd);

    n = Rio_readlineb(&rio, buf, MAXLINE);
    Rio_writen(STDOUT_FILENO, buf, n);

    n = Rio_readlineb(&rio, buf, MAXLINE);
    Rio_writen(STDOUT_FILENO, buf, n);

    n = Rio_readlineb(&rio, buf, MAXLINE);
    Rio_writen(STDOUT_FILENO, buf, n);

    fd = Open("test.txt", O_RDONLY, NULL);
    Read(fd, buf, 5);
    Rio_writen(STDOUT_FILENO, buf, 5);
    Read(fd, buf, 6);
    Rio_writen(STDOUT_FILENO, buf, 6);

    exit(0);
}