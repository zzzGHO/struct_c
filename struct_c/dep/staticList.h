#ifndef __STACKLIST_H__
#define __STACKLIST_H__

#include <stdio.h>
#define ElemType int
#define MAX_SIZE 10

typedef struct {
	ElemType data;		// 数据域
	int cur;			// 游标
}ListNode;

typedef ListNode static_list[MAX_SIZE];

void InitStaticList(static_list* list);
int malloc_static_list(static_list* list);
void free_static_list(static_list* list, int index);
void push_static_list(static_list* list, ElemType elem);
void pop_static_list(static_list* list);
void print_static_list(static_list* list);
#endif // !__STACKLIST_H__
