#include <stdio.h>

#include "../include/notebook.h"

int main(void) {
    Notebook nb;
    int choice = -1;
    const char *save_path = "c-basics/c_lab_notebook/data/notebook.db";

    nb_init(&nb);
    nb_load_from_file(&nb, save_path);

    while (choice != 0) {
        printf("\n===== C-Lab Notebook =====\n");
        printf("1. 新增记录\n");
        printf("2. 查看全部\n");
        printf("3. 删除记录\n");
        printf("4. 关键词查找\n");
        printf("5. 按 ID 排序\n");
        printf("6. 保存记录\n");
        printf("0. 退出\n");
        printf("请选择: ");

        if (scanf("%d", &choice) != 1) {
            printf("输入无效，程序结束。\n");
            break;
        }
        while (getchar() != '\n') {
        }

        switch (choice) {
            case 1:
                nb_prompt_add(&nb);
                break;
            case 2:
                nb_print_all(&nb);
                break;
            case 3:
                nb_prompt_delete(&nb);
                break;
            case 4:
                nb_prompt_find(&nb);
                break;
            case 5:
                nb_sort_by_id(&nb);
                printf("已按 ID 排序。\n");
                break;
            case 6:
                nb_save_to_file(&nb, save_path);
                break;
            case 0:
                nb_save_to_file(&nb, save_path);
                printf("已保存并退出。\n");
                break;
            default:
                printf("无效选项。\n");
                break;
        }
    }

    nb_destroy(&nb);
    return 0;
}
