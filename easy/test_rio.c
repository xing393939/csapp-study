#include "csapp.h"

int main(int argc, char **argv) {
    int n;
    rio_t rio;
    char buf[MAXLINE];

    int fd = Open("cmake_install.cmake", O_RDONLY, NULL);
    Rio_readinitb(&rio, fd);

    n = Rio_readlineb(&rio, buf, MAXLINE);
    Rio_writen(STDOUT_FILENO, buf, n);

    n = Rio_readlineb(&rio, buf, MAXLINE);
    Rio_writen(STDOUT_FILENO, buf, n);

    n = Rio_readlineb(&rio, buf, MAXLINE);
    Rio_writen(STDOUT_FILENO, buf, n);

    exit(0);
}