#include <stdio.h>

struct{
    char c;
    int i[2];
    double v;
}A;

int main(void) {
    printf("the size of struct A：%d",sizeof(A));
}
