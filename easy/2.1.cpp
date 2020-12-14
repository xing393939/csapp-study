#include <stdio.h>

struct {
    char c;
    int i[2];
    double v;
} A;

void echo() {
    char buf[4]; // 太小
    scanf("%s", buf);
    puts(buf);
}

int main(void) {
    echo();
    return 0;
    //printf("the size of struct A：%d",sizeof(A));
}
