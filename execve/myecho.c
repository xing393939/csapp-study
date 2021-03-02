#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    int i;
    printf("arguments: %d\n", argc);
    for (i = 0; argv[i] != NULL; i++)
        printf(" argv[%2d]: %s\n", i, argv[i]);
    for (i = 0; envp[i] != NULL; i++)
        printf(" envp[%2d]: %s\n", i, envp[i]);
    return 0;
}
