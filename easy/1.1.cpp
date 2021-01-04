#include <stdio.h>

typedef unsigned char *pointer;

void show_bytes(pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf("%p %.2x\n", start+i, start[i]);
    printf("\n");
}

int main(void) {
    /**
     * 检测机器是不是小端规则
     * 存储是从低地址->高地址，所以是小端规则
     */
    char a[5] = "0123";
    printf("char a = %p\n", &a);
    show_bytes((pointer) &a, 4);
}
