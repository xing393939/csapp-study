#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void unix_error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    _exit(0);
}

int main() {
    char *arg[2] = {"arg1", (char *) 0};
    char *env[2] = {"env1", (char *) 0};
    int rc = execve("./myecho", arg, env);
    if (rc == -1) unix_error("");
    printf("success.\n");
    return 0;
}
