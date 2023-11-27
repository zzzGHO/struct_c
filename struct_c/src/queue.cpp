#include <stdio.h>
#include <stdlib.h>
#include "../dep/queue.h"

queue* InitQueue(void) {
	queue* head = (queue*)malloc(sizeof(queue));
	head->front = NULL;
	head->rear = NULL;
	head->size = 0;
	return head;
}

void push_queue(queue* sta, ElemType elem) {
	queue_node* temp = (queue_node*)malloc(sizeof(queue_node));
	if (temp) {
		sta->size++;
		temp->data = elem;
		if (sta->rear == NULL) {
			sta->front = temp;
		}
		else {
			sta->rear->pNext = temp;
		}
		sta->rear = temp;
		temp->pNext = NULL;
	}
}

void pop_queue(queue* sta) {
	if (sta->size < 1) {
		printf("Error!\n");
		return;
	}
	queue_node* temp = sta->front;
	sta->front = temp->pNext;
	free(temp);
	sta->size--;
}

ElemType get_front_queue(queue* sta) {
	if (!sta->front) {
		printf("Error");
		return -1;
	}
	else {
		return sta->front->data;
	}
}

ElemType get_back_queue(queue* sta) {
	if (!sta->rear) {
		printf("Error");
		return -1;
	}
	else {
		return sta->rear->data;
	}
}

void print_queue(queue* sta) {
	queue_node* temp = sta->front;
	while (temp != NULL) {
		printf("%d,", temp->data);
		temp = temp->pNext;
	}
	printf("\n");
}

int size_queue(queue* sta) {
	return sta->size;
}

void clear_queue(queue* sta) {
	while (sta->front) {
		pop_queue(sta);
	}
}