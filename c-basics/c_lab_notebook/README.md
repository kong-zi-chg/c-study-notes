# C-Lab Notebook（纯 C）

一个命令行学习记录工具，定位是“你的技术错题本 + 代码片段本”。

## 为什么这个项目有含金量

- 不是烂大街学生管理系统，贴近真实学习场景
- 核心实现会用到指针、动态内存、结构体数组、文件读写
- 能体现你从“会写语法”到“能做小系统”的能力
- 后续可扩展成 AI 时代数据预处理小工具

## 分工（固定）

- 你负责：`src/core_todo.c`（核心算法与数据结构）
- 我负责：项目框架、菜单流程、输入输出、防呆处理、README、目录规范

## 你要实现的核心函数

在 `src/core_todo.c` 里完成：

1. `nb_add_record()`：动态扩容 + 追加记录
2. `nb_delete_by_id()`：按 id 删除并搬移元素
3. `nb_find_by_keyword()`：按关键词查找标题/内容
4. `nb_sort_by_id()`：按 id 排序（可用 qsort）

## 目录

```text
c_lab_notebook/
├─ include/
│  └─ notebook.h
├─ src/
│  ├─ main.c          # 菜单入口（已完成）
│  ├─ framework.c     # 框架功能（已完成）
│  └─ core_todo.c     # 你来实现核心（待完成）
└─ data/
   └─ .gitkeep
```

## 运行（有 gcc 时）

```bash
gcc src/main.c src/framework.c src/core_todo.c -o c_lab_notebook
./c_lab_notebook
```
