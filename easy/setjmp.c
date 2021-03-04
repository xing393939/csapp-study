#include "csapp.h"

sigjmp_buf buf;

int error1 = 0;
int error2 = 1;

void foo(void), bar(void);

int main() {
    switch (sigsetjmp(buf, 1)) {
        case 0:
            foo();
            break;
        case 1:
            printf("Detected an error1 condition in foo\n");
            break;
        case 2:
            printf("Detected an error2 condition in foo\n");
            break;
        default:
            printf("Unknown error condition in foo\n");
    }
    exit(0);
}

/* Deeply nested function foo */
void foo(void) {
    if (error1)
        siglongjmp(buf, 1);
    bar();
}

void bar(void) {
    if (error2)
        siglongjmp(buf, 2);
}