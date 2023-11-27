#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include "dynamic_list.h"

typedef dynamic_ListNode stack_node;
typedef dynamic_List stack;

stack* InitStack(void);
void push_stack(stack* sta, ElemType elem);
void pop_stack(stack* sta);
ElemType get_top_stack(stack* sta);
void print_stack(stack* sta);
int size_stack(stack* sta);
void clear_stack(stack* sta);
#endif
