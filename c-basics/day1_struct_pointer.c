#include <stdio.h>
#include <string.h>

typedef struct {
    char date[20];
    char address[30];
    char name[30];
} Student;

void fill_student(Student *p) {
    strcpy(p->date, "3.24");
    strcpy(p->address, "北京");
    strcpy(p->name, "小王");
}

int main() {
    Student a[2];

    fill_student(&a[0]);
    strcpy(a[1].date, "3.25");
    strcpy(a[1].address, "广州");
    strcpy(a[1].name, "小唐");

    for (int i = 0; i < 2; i++) {
        printf("日期%s，地点%s，名字%s\n", a[i].date, a[i].address, a[i].name);
    }

    return 0;
}
