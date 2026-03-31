#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#define NB_TOPIC_MAX 32
#define NB_TITLE_MAX 64
#define NB_NOTE_MAX 256
#define NB_TIME_MAX 20

typedef struct {
    int id;
    char topic[NB_TOPIC_MAX];
    char title[NB_TITLE_MAX];
    char note[NB_NOTE_MAX];
    char created_at[NB_TIME_MAX];
} NoteRecord;

typedef struct {
    NoteRecord *items;
    int size;
    int capacity;
    int next_id;
} Notebook;

void nb_init(Notebook *nb);
void nb_destroy(Notebook *nb);

void nb_print_all(const Notebook *nb);
void nb_prompt_add(Notebook *nb);
void nb_prompt_delete(Notebook *nb);
void nb_prompt_find(const Notebook *nb);
void nb_save_to_file(const Notebook *nb, const char *path);
void nb_load_from_file(Notebook *nb, const char *path);

int nb_add_record(Notebook *nb, const char *topic, const char *title, const char *note);
int nb_delete_by_id(Notebook *nb, int id);
int nb_find_by_keyword(const Notebook *nb, const char *keyword);
void nb_sort_by_id(Notebook *nb);

void read_line(char *buf, int max_len);
void now_time(char *buf, int max_len);

#endif
