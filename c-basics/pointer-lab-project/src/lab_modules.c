#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/lab_modules.h"

typedef struct {
    char date[20];
    char address[30];
    char name[30];
} Student;

static void bad_alloc(int *p) {
    p = malloc(sizeof(int));
    if (p != NULL) {
        *p = 100;
    }
}

static void good_alloc(int **p) {
    *p = malloc(sizeof(int));
    if (*p != NULL) {
        **p = 100;
    }
}

void run_basic_pointer_demo(void) {
    int a = 5;
    int *b = malloc(sizeof(int));

    if (b == NULL) {
        printf("malloc 失败\n");
        return;
    }

    *b = 10;
    printf("\n[基础指针]\n");
    printf("a 的值=%d, a 的地址=%p\n", a, (void *)&a);
    printf("b 存的地址=%p, *b 的值=%d\n", (void *)b, *b);
    printf("b 变量自己的地址=%p\n", (void *)&b);

    free(b);
    b = NULL;
}

void run_array_pointer_demo(void) {
    int *arr = malloc(sizeof(int) * 5);
    if (arr == NULL) {
        printf("malloc 失败\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
        arr[i] = 89;
    }
    *(arr + 3) = 88;

    printf("\n[数组与指针等价]\n");
    printf("arr[i] 与 *(arr+i) 等价，当前数组为: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
}

void run_struct_pointer_demo(void) {
    Student *s = malloc(sizeof(Student));
    if (s == NULL) {
        printf("malloc 失败\n");
        return;
    }

    strcpy(s->date, "3.29");
    strcpy(s->address, "北京");
    strcpy(s->name, "小王");

    printf("\n[结构体指针]\n");
    printf("日期=%s, 地点=%s, 名字=%s\n", s->date, s->address, s->name);

    free(s);
    s = NULL;
}

void run_double_pointer_demo(void) {
    int *p = NULL;

    bad_alloc(p);
    printf("\n[二级指针]\n");
    printf("bad_alloc 后 p 仍是 %p（没改到外部 p）\n", (void *)p);

    good_alloc(&p);
    if (p != NULL) {
        printf("good_alloc 后 p 指向 %p, *p=%d\n", (void *)p, *p);
        free(p);
        p = NULL;
    } else {
        printf("good_alloc 分配失败\n");
    }
}
