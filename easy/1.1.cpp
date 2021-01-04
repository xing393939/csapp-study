#include <stdio.h>

typedef unsigned char *pointer;

void show_bytes(pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf("%p %.2x\n", start+i, start[i]);
    printf("\n");
}

int main(void) {
    char a[5] = "0123";
    printf("char a = %p\n", &a);
    show_bytes((pointer) &a, 4);

    /**
     * 检测机器是不是小端规则（需要用多字节的数据来验证，不能用char）
     * 小端尾规则=尾部是低地址
     */
    int b = 15213; //16进制是00 00 3b 6d
    printf("int b = 15213;\n");
    show_bytes((pointer) &b, sizeof(int));
}
