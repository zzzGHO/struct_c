#include <stdio.h>
#include <stdlib.h>
#include "../dep/dynamic_list.h"

dynamic_List* InitDynamicList(void) {
	dynamic_List* head = (dynamic_List*)malloc(sizeof(dynamic_List));
	if (head) {
		head->pNext = NULL;
		head->size = 0;
	}
	return head;
}

void push_dynamic_list(dynamic_List* list, ElemType elem) {
	dynamic_ListNode* newNode = (dynamic_ListNode*)malloc(sizeof(dynamic_ListNode));
	if (newNode) {
		newNode->data = elem;
		if (list->pNext == NULL) {
			newNode->pNext = NULL;
		}
		else {
			newNode->pNext = list->pNext;
		}
		list->pNext = newNode;
		list->size++;
	}
}

void pop_dynamic_list(dynamic_List* list) {
	if (list->size > 0) {
		dynamic_ListNode* temp = list->pNext;
		list->pNext = temp->pNext;
		free(temp);
		list->size--;
	}
}

void print_dynamic_list(dynamic_List* list) {
	dynamic_ListNode* temp = list->pNext;
	while (temp != NULL) {
		printf("%d,", temp->data);
		temp = temp->pNext;
	}
	printf("\n");
}

int size_circular_list(dynamic_List* list) {
	return list->size;
}