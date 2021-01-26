#include <stdio.h>

#define Length(x) sizeof(x)/sizeof(x[0])

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y; /* Step 1 */
    *x = *x ^ *y; /* Step 2 */
    *y = *x ^ *y; /* Step 3 */
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--)
        inplace_swap(&a[first], &a[last]);
}

int main() {
    int a[5] = {2, 1, 3, 4, 5};
    printf("%d %d\n", a[0], a[1]);
    inplace_swap(a, a + 1);
    printf("%d %d\n", a[0], a[1]);
    reverse_array(a, Length(a));
    for (int i = 0; i < Length(a); i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
