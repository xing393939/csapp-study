#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

void P2() {
    printf("IN P2 1\n");
    if (setjmp(env)) {
        printf("IN P2 2\n");
    }
    printf("IN P2 3\n");
}

void P3() {
    printf("IN P3 1\n");
    longjmp(env, 1);
}

int main() {
    printf("IN main 1\n");
    P2();
    printf("IN main 2\n");
    P3();
    printf("IN main 3\n");
}

