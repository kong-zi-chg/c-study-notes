#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/notebook.h"

int nb_add_record(Notebook *nb, const char *topic, const char *title, const char *note) {
    if (nb == NULL || topic == NULL || title == NULL || note == NULL) {
        return -1;
    }

    if (nb->size >= nb->capacity) {
        int new_capacity = (nb->capacity > 0) ? nb->capacity * 2 : 4;
        NoteRecord *new_items = (NoteRecord *)realloc(
            nb->items,
            sizeof(NoteRecord) * new_capacity
        );
        if (new_items == NULL) {
            return -1;
        }
        nb->items = new_items;
        nb->capacity = new_capacity;
    }

    NoteRecord *r = &nb->items[nb->size];

    r->id = nb->next_id;
    snprintf(r->topic, NB_TOPIC_MAX, "%s", topic);
    snprintf(r->title, NB_TITLE_MAX, "%s", title);
    snprintf(r->note, NB_NOTE_MAX, "%s", note);
    now_time(r->created_at, NB_TIME_MAX);

    nb->size++;
    nb->next_id++;
    return 0;
}

int nb_delete_by_id(Notebook *nb, int id) {
    if (nb == NULL || nb->size == 0) {
        return -1;
    }

    int idx = -1;
    for (int i = 0; i < nb->size; i++) {
        if (nb->items[i].id == id) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        return -1;
    }

    for (int i = idx; i < nb->size - 1; i++) {
        nb->items[i] = nb->items[i + 1];
    }
    nb->size--;
    return 0;
}

int nb_find_by_keyword(const Notebook *nb, const char *keyword) {
    if (nb == NULL || keyword == NULL || keyword[0] == '\0') {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < nb->size; i++) {
        const NoteRecord *r = &nb->items[i];
        if (strstr(r->title, keyword) != NULL || strstr(r->note, keyword) != NULL) {
            printf("ID:%d | [%s] %s\n", r->id, r->topic, r->title);
            printf("时间:%s\n", r->created_at);
            printf("内容:%s\n", r->note);
            printf("--------------------------\n");
            count++;
        }
    }
    return count;
}

static int cmp_record_id(const void *a, const void *b) {
    const NoteRecord *ra = (const NoteRecord *)a;
    const NoteRecord *rb = (const NoteRecord *)b;
    if (ra->id < rb->id) return -1;
    if (ra->id > rb->id) return 1;
    return 0;
}

void nb_sort_by_id(Notebook *nb) {
    if (nb == NULL || nb->size <= 1) {
        return;
    }
    qsort(nb->items, nb->size, sizeof(NoteRecord), cmp_record_id);
}
