#include <stdio.h>
#include <stdlib.h>
#include "../dep/circular_list.h"

Circular_List* InitCircularList(void) {
	Circular_List* head = (Circular_List*)malloc(sizeof(Circular_List));
	if (head) {
		head->pNext = NULL;
		head->pPrior = NULL;
		head->size = 0;
	}
	return head;
}

void push_front_circular_list(Circular_List* list, ElemType elem) {
	circular_ListNode* temp = (circular_ListNode*)malloc(sizeof(circular_ListNode));
	if (temp) {
		list->size++;
		temp->data = elem;
		if (list->pNext == NULL) {
			temp->pNext = temp;
			list->pPrior = temp;
		}
		else {
			temp->pNext = list->pNext;
			list->pNext->pPrior = temp;
		}
		list->pNext = temp;
		temp->pPrior = list->pPrior;
		list->pPrior->pNext = temp;
	}
}

void push_back_circular_list(Circular_List* list, ElemType elem) {
	circular_ListNode* temp = (circular_ListNode*)malloc(sizeof(circular_ListNode));
	if (temp) {
		list->size++;
		temp->data = elem;
		if (list->pPrior == NULL) {
			temp->pPrior = temp;
			list->pNext = temp;
		}
		else {
			temp->pPrior = list->pPrior;
			list->pPrior->pNext = temp;
		}
		list->pPrior = temp;
		temp->pNext = list->pNext;
		list->pNext->pPrior = temp;
	}
}

void pop_front_circular_list(Circular_List* list) {
	pop_circular_list(list, list->pNext);
}

void pop_back_circular_list(Circular_List* list) {
	pop_circular_list(list, list->pPrior);
}

void pop_circular_list(Circular_List* list, circular_ListNode* node) {
	if (list->size < 1) {
		printf("Error!\n");
	}
	list->size--;
	node->pPrior->pNext = node->pNext;
	node->pNext->pPrior = node->pPrior;
	if (node == list->pNext) {
		list->pNext = node->pNext;
	}
	else if (node == list->pPrior) {
		list->pPrior = node->pPrior;
	}
	free(node);
}

void print_front_circular_list(Circular_List* list, int loop) {
	circular_ListNode* temp = list->pNext;
	while (loop) {
		printf("%d,", temp->data);
		temp = temp->pNext;
		loop--;
	}
	printf("\n");
}

void print_back_circular_list(Circular_List* list) {
	circular_ListNode* temp = list->pPrior;
	while (temp != NULL) {
		printf("%d,", temp->data);
		temp = temp->pPrior;
	}
	printf("\n");
}

int size_circular_list(Circular_List* list) {
	return list->size;
}