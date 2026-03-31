#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/notebook.h"

int nb_add_record(Notebook *nb, const char *topic, const char *title, const char *note) {
    // TODO(你来实现):
    // 1) 如果 size == capacity，做扩容（建议 *2）
    // 2) 填充新记录：id / topic / title / note / created_at
    // 3) size++，next_id++
    // 4) 成功返回 0，失败返回 -1

    (void)nb;
    (void)topic;
    (void)title;
    (void)note;
    return -1;
}

int nb_delete_by_id(Notebook *nb, int id) {
    // TODO(你来实现):
    // 1) 找到 id 对应下标
    // 2) 之后元素整体前移一位
    // 3) size--
    // 4) 找到返回 0，没找到返回 -1

    (void)nb;
    (void)id;
    return -1;
}

int nb_find_by_keyword(const Notebook *nb, const char *keyword) {
    // TODO(你来实现):
    // 1) 在 title 或 note 中做包含匹配（strstr）
    // 2) 每命中一条就打印该记录简要信息
    // 3) 返回命中数量

    (void)nb;
    (void)keyword;
    return 0;
}

static int cmp_record_id(const void *a, const void *b) {
    const NoteRecord *ra = (const NoteRecord *)a;
    const NoteRecord *rb = (const NoteRecord *)b;
    if (ra->id < rb->id) return -1;
    if (ra->id > rb->id) return 1;
    return 0;
}

void nb_sort_by_id(Notebook *nb) {
    // TODO(你来实现):
    // 用 qsort 对 nb->items 按 id 升序排序
    // 提示: qsort(base, nitems, size, cmp)

    (void)cmp_record_id; // 去掉你实现前的未使用警告
    (void)nb;
}
