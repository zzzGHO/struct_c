#include <stdio.h>
#include "../dep/staticList.h"

void InitStaticList(static_list* list) {
	for (int i = 0; i < MAX_SIZE - 1; ++i) {
		list[i]->cur = i + 1;
	}
	list[0]->cur = -1;
	list[MAX_SIZE - 1]->cur = 0;
}

int malloc_static_list(static_list* list) {
	int i = list[1]->cur;
	if (i) {
		list[1]->cur = list[i]->cur;
	}
	return i;
}

void free_static_list(static_list* list, int index) {
	list[index]->cur = list[1]->cur;
	list[1]->cur = index;
}

void push_static_list (static_list* list, ElemType elem) {
	int empty_index = malloc_static_list(list);
	if (empty_index == 0) {
		printf("Failed!\n");
	}
	list[empty_index]->data = elem;
	if (list[0]->cur == -1) {
		list[empty_index]->cur = -1;
	}
	else {
		list[empty_index]->cur = list[0]->cur;
	}
	list[0]->cur = empty_index;
}

void pop_static_list(static_list* list) {
	list[0]->cur = list[list[0]->cur]->cur;
}

void print_static_list(static_list* list) {
	int index = list[0]->cur;
	while (index != -1) {
		printf("%d,", list[index]->data);
		index = list[index]->cur;
	}
	printf("\n");
}
