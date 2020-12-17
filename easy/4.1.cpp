#include <stdio.h>

int gInitVar = 84;  // 初始化的全局变量；
int gUnintVar;  // 未初始化的全局变量；

int f() {
    static int x = 0;
    return x;
}

int g() {
    static int x = 1;
    return x;
}

int main() {
    f();
    g();
}