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
     * 检测机器是不是小端规则，这里15213的16进制是00 00 3b 6d
     * 存储是从低地址->高地址，所以是小端规则
     */
    int a = 15213;
    printf("int a = 15213;\n");
    show_bytes((pointer) &a, sizeof(int));
}
