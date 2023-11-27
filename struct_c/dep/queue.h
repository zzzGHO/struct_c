#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdio.h>
#define ElemType int
typedef struct que_node {
	ElemType data;				// ������
	struct que_node* pNext;	// ָ���¸��ڵ��ָ��
}queue_node;
  
typedef struct {
	queue_node* front;
	queue_node* rear;
	size_t size;
}queue;

queue* InitQueue(void);
void push_queue(queue* sta, ElemType elem);
void pop_queue(queue* sta);
ElemType get_front_queue(queue* sta);
ElemType get_back_queue(queue* sta);
void print_queue(queue* sta);
int size_queue(queue* sta);
void clear_queue(queue* sta);

#endif