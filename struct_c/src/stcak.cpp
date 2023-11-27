#include <stdio.h>
#include "../dep/stack.h"
#include "../dep/dynamic_list.h"

stack* InitStack(void) {
	stack* stacktop = InitDynamicList();
	return stacktop;
}

void push_stack(stack* sta, ElemType elem) {
	push_dynamic_list(sta, elem);
}

void pop_stack(stack* sta) {
	pop_dynamic_list(sta);
}

ElemType get_top_stack(stack* sta) {
	if (!sta->pNext) {
		printf("Error");
		return -1;
	}
	else {
		return sta->pNext->data;
	}
}

void print_stack(stack* sta) {
	print_dynamic_list(sta);
}

int size_stack(stack* sta) {
	return size_dynamic_list(sta);
}

void clear_stack(stack* sta) {
	while (sta->pNext) {
		pop_stack(sta);
	}
}