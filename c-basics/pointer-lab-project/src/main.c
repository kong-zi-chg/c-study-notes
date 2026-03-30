#include <stdio.h>

#include "../include/lab_modules.h"

int main(void) {
    int choice = -1;

    while (choice != 0) {
        printf("\n==== Pointer Lab Project ====\n");
        printf("1. 基础指针: a / p / *p / &p\n");
        printf("2. 数组与指针等价: arr[i] vs *(arr+i)\n");
        printf("3. 结构体指针: s->field\n");
        printf("4. 二级指针: 为什么需要 int**\n");
        printf("0. 退出\n");
        printf("请输入选项: ");

        if (scanf("%d", &choice) != 1) {
            printf("输入无效，程序结束。\n");
            return 1;
        }

        switch (choice) {
            case 1:
                run_basic_pointer_demo();
                break;
            case 2:
                run_array_pointer_demo();
                break;
            case 3:
                run_struct_pointer_demo();
                break;
            case 4:
                run_double_pointer_demo();
                break;
            case 0:
                printf("已退出。\n");
                break;
            default:
                printf("没有这个选项，请重试。\n");
        }
    }

    return 0;
}
