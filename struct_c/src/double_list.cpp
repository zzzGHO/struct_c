#include <stdio.h>
#include <stdlib.h>
#include "../dep/double_list.h"

double_List* InitDoubleList(void) {
	double_List* head = (double_List*)malloc(sizeof(double_List));
	if (head) {
		head->pNext = NULL;
		head->pPrior = NULL;
		head->size = 0;
	}
	return head;
}

void push_front_double_list(double_List* list, ElemType elem) {
	double_ListNode* temp = (double_ListNode*)malloc(sizeof(double_ListNode));
	if (temp) {
		temp->data = elem;
		if (list->pNext == NULL) {
			temp->pNext = NULL;
			list->pPrior = temp;
		}
		else {
			temp->pNext = list->pNext;
			list->pNext->pPrior = temp;
		}
		list->pNext = temp;
		temp->pPrior = NULL;
		list->size++;
	}
}

void push_back_double_list(double_List* list, ElemType elem) {
	double_ListNode* temp = (double_ListNode*)malloc(sizeof(double_ListNode));
	if (temp) {
		temp->data = elem;
		if (list->pPrior == NULL) {
			temp->pPrior = NULL;
			list->pNext = temp;
		}
		else {
			temp->pPrior = list->pPrior;
			list->pPrior->pNext = temp;
		}
		list->pPrior = temp;
		temp->pNext = NULL;
		list->size++;
	}
}

void pop_front_double_list(double_List* list) {
	if (list->size > 0) {
		double_ListNode* temp = list->pNext;
		list->pNext = temp->pNext;
		temp->pNext->pPrior = temp->pPrior;
		free(temp);
		list->size--;
	}
}

void pop_back_double_list(double_List* list) {
	if (list->size > 0) {
		double_ListNode* temp = list->pPrior;
		list->pPrior = temp->pPrior;
		temp->pPrior->pNext = temp->pNext;
		free(temp);
		list->size--;
	}
}

void print_front_double_list(double_List* list) {
	double_ListNode* temp = list->pNext;
	while (temp != NULL) {
		printf("%d,", temp->data);
		temp = temp->pNext;
	}
	printf("\n");
}

void print_back_double_list(double_List* list) {
	double_ListNode* temp = list->pPrior;
	while (temp != NULL) {
		printf("%d,", temp->data);
		temp = temp->pPrior;
	}
	printf("\n");
}

int size_circular_list(double_List* list) {
	return list->size;
}