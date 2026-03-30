# Pointer Lab Project

这是一个把你当前 C 语言核心卡点整合到一起的练习项目。

## 项目目标

- 把零散知识变成可运行的模块
- 每次只改一个模块，便于复习和扩展
- 形成对外可展示的“持续学习项目”

## 已包含模块

1. 基础指针（`a / p / *p / &p`）
2. 数组与指针等价（`arr[i]` 与 `*(arr+i)`）
3. 结构体指针（`->` 与 `(*p).field`）
4. 二级指针（为什么要 `int**`）

## 目录结构

```text
pointer-lab-project/
├─ include/
│  └─ lab_modules.h
├─ src/
│  ├─ main.c
│  └─ lab_modules.c
└─ README.md
```

## 运行方式

如果你本机有 gcc，可以在项目目录执行：

```bash
gcc src/main.c src/lab_modules.c -o pointer_lab
./pointer_lab
```

## 后续扩展建议

- 新增 `string` 模块：`strcpy`、`\0`、`strlen/sizeof`
- 新增 `list` 模块：链表创建、插入、删除
- 每个模块加 2-3 个自测题
