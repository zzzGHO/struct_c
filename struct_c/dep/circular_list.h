#ifndef __CIRCULARLIST_H__
#define __CIRCULARLIST_H__
#include <stdio.h>
#define ElemType int

typedef struct cir_listnode {
	ElemType data;		// 数据域
	cir_listnode* pPrior;// 指向上个节点的指针
	cir_listnode* pNext;	// 指向下个节点的指针
}circular_ListNode;
typedef struct cir_list {
	circular_ListNode* pPrior;
	circular_ListNode* pNext;
	size_t size;
}Circular_List;

Circular_List* InitCircularList(void);
void push_front_circular_list(Circular_List* list, ElemType elem);
void push_back_circular_list(Circular_List* list, ElemType elem);
void pop_front_circular_list(Circular_List* list);
void pop_back_circular_list(Circular_List* list);
void pop_circular_list(Circular_List* list, circular_ListNode* node);
void print_front_circular_list(Circular_List* list, int loop);
void print_back_circular_list(Circular_List* list);
int size_circular_list(Circular_List* list);
#endif // !__STACKLIST_H__
