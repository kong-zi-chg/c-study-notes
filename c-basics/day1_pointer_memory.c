#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 5;                 // 栈变量
    int *b = malloc(sizeof(int)); // 堆内存

    if (b == NULL) {
        return 1;
    }

    *b = 10;

    printf("a的值: %d, a的地址: %p\n", a, (void *)&a);
    printf("b存的地址: %p, *b的值: %d\n", (void *)b, *b);
    printf("b变量自己的地址: %p\n", (void *)&b);

    free(b);
    b = NULL;
    return 0;
}
