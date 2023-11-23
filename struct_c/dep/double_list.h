#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__

#include <stdio.h>
#define ElemType int
typedef struct dou_listnode {
	ElemType data;		// 数据域
	struct dou_listnode* pPrior;// 指向上个节点的指针
	struct dou_listnode* pNext;	// 指向下个节点的指针
}double_ListNode;

typedef struct dou_list {
	double_ListNode* pPrior;
	double_ListNode* pNext;
	size_t size;
}double_List;
double_List* InitDoubleList(void);
void push_front_double_list(double_List* list, ElemType elem);
void push_back_double_list(double_List* list, ElemType elem);
void pop_front_double_list(double_List* list);
void pop_back_double_list(double_List* list);
void print_front_double_list(double_List* list);
void print_back_double_list(double_List* list);
int size_circular_list(double_List* list);
#endif // !__STACKLIST_H__
