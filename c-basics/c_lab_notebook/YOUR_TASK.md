# 你今天要完成的模块

你只需要改一个文件：`src/core_todo.c`

## 必做 1：`nb_add_record`

- 满容量时扩容（建议 `capacity *= 2`）
- 追加一条记录并写入时间
- 成功返回 `0`，失败返回 `-1`

## 必做 2：`nb_delete_by_id`

- 按 id 找记录
- 删除后把后面的元素前移
- 找到返回 `0`，没找到返回 `-1`

## 必做 3：`nb_find_by_keyword`

- 用 `strstr` 在 `title` 或 `note` 中匹配关键词
- 打印命中记录
- 返回命中数量

## 必做 4：`nb_sort_by_id`

- 用 `qsort` 按 `id` 升序排序

---

完成后把 `core_todo.c` 发给我，我做逐行代码审查。
