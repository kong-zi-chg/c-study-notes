#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/notebook.h"

void nb_init(Notebook *nb) {
    nb->size = 0;
    nb->capacity = 4;
    nb->next_id = 1;
    nb->items = (NoteRecord *)malloc(sizeof(NoteRecord) * nb->capacity);
    if (nb->items == NULL) {
        nb->capacity = 0;
    }
}

void nb_destroy(Notebook *nb) {
    free(nb->items);
    nb->items = NULL;
    nb->size = 0;
    nb->capacity = 0;
    nb->next_id = 1;
}

void read_line(char *buf, int max_len) {
    if (fgets(buf, max_len, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\r\n")] = '\0';
}

void now_time(char *buf, int max_len) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    if (tm_info == NULL) {
        snprintf(buf, max_len, "unknown");
        return;
    }
    strftime(buf, max_len, "%Y-%m-%d %H:%M:%S", tm_info);
}

void nb_print_all(const Notebook *nb) {
    if (nb->size == 0) {
        printf("当前没有记录。\n");
        return;
    }
    printf("\n---- 全部记录（%d 条）----\n", nb->size);
    for (int i = 0; i < nb->size; i++) {
        const NoteRecord *r = &nb->items[i];
        printf("ID:%d | [%s] %s\n", r->id, r->topic, r->title);
        printf("时间: %s\n", r->created_at);
        printf("内容: %s\n", r->note);
        printf("--------------------------\n");
    }
}

void nb_prompt_add(Notebook *nb) {
    char topic[NB_TOPIC_MAX];
    char title[NB_TITLE_MAX];
    char note[NB_NOTE_MAX];

    printf("输入主题: ");
    read_line(topic, NB_TOPIC_MAX);
    printf("输入标题: ");
    read_line(title, NB_TITLE_MAX);
    printf("输入内容: ");
    read_line(note, NB_NOTE_MAX);

    if (nb_add_record(nb, topic, title, note) == 0) {
        printf("新增成功。\n");
    } else {
        printf("新增失败（可能是内存不足）。\n");
    }
}

void nb_prompt_delete(Notebook *nb) {
    int id = 0;
    printf("输入要删除的 id: ");
    if (scanf("%d", &id) != 1) {
        printf("输入无效。\n");
        while (getchar() != '\n') {
        }
        return;
    }
    while (getchar() != '\n') {
    }
    if (nb_delete_by_id(nb, id) == 0) {
        printf("删除成功。\n");
    } else {
        printf("未找到该 id。\n");
    }
}

void nb_prompt_find(const Notebook *nb) {
    char keyword[NB_TITLE_MAX];
    printf("输入关键词: ");
    read_line(keyword, NB_TITLE_MAX);
    int count = nb_find_by_keyword(nb, keyword);
    printf("匹配到 %d 条。\n", count);
}

void nb_save_to_file(const Notebook *nb, const char *path) {
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        printf("保存失败：无法打开文件。\n");
        return;
    }
    fprintf(fp, "%d %d %d\n", nb->size, nb->capacity, nb->next_id);
    for (int i = 0; i < nb->size; i++) {
        const NoteRecord *r = &nb->items[i];
        fprintf(fp, "%d\n%s\n%s\n%s\n%s\n",
                r->id, r->topic, r->title, r->note, r->created_at);
    }
    fclose(fp);
    printf("已保存到 %s\n", path);
}

void nb_load_from_file(Notebook *nb, const char *path) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("未找到历史文件，使用空记录启动。\n");
        return;
    }

    int size = 0, cap = 0, next_id = 1;
    if (fscanf(fp, "%d %d %d\n", &size, &cap, &next_id) != 3) {
        fclose(fp);
        printf("历史文件格式错误，忽略。\n");
        return;
    }

    NoteRecord *new_items = (NoteRecord *)malloc(sizeof(NoteRecord) * (cap > 0 ? cap : 4));
    if (new_items == NULL) {
        fclose(fp);
        printf("加载失败：内存不足。\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        NoteRecord *r = &new_items[i];
        if (fscanf(fp, "%d\n", &r->id) != 1) {
            free(new_items);
            fclose(fp);
            printf("历史文件中断，忽略加载。\n");
            return;
        }
        read_line(r->topic, NB_TOPIC_MAX);
        read_line(r->title, NB_TITLE_MAX);
        read_line(r->note, NB_NOTE_MAX);
        read_line(r->created_at, NB_TIME_MAX);
    }

    free(nb->items);
    nb->items = new_items;
    nb->size = size;
    nb->capacity = cap > 0 ? cap : 4;
    nb->next_id = next_id;

    fclose(fp);
    printf("已加载 %d 条历史记录。\n", nb->size);
}
