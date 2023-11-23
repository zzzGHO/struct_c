#ifndef __DYNAMICLIST_H__
#define __DYNAMICLIST_H__
#include <stdio.h>
#define ElemType int

typedef struct dyn_listnode {
	ElemType data;		// 数据域
	struct dyn_listnode* pNext;	// 指向下个节点的指针
}dynamic_ListNode;

typedef struct dyn_list {
	dynamic_ListNode* pNext;
	size_t size;
}dynamic_List;

dynamic_List* InitDynamicList(void);
void push_dynamic_list(dynamic_List* list, ElemType elem);
void pop_dynamic_list(dynamic_List* list);
void print_dynamic_list(dynamic_List* list);
int size_circular_list(dynamic_List* list);
#endif // !__DYNAMICLIST_H__
