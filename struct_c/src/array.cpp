#include <stdio.h>
#include <stdlib.h>	// malloc��Ҫ
#include "../dep/array.h"


array_Node* initArray(int n) {
	array_Node* t = (array_Node*)malloc(sizeof(array_Node));
	if (t) {
		t->head = (int*)malloc(n * sizeof(int));
		if (!t->head) {
			printf("Failed Init!");
			exit(0);
		}
		t->size = 0;
		t->capacity = n;
		return t;
	}
}

void print_array(array_Node* t) {
	for (int i = 0; i < t->size; ++i) {
		printf("%d,", t->head[i]);
	}
	printf("\n");
}
/**
  * @brief  �������в�������
  * @param  table* t �����ַ, int elem ��������, int pos ��������(λ��)
  * @retval None
  */
void addTable(array_Node* t, int elem, int pos) {
	if (pos > t->size || pos < 0) {		// �������鷶Χ������������
		return;
	}
	if (t->size == t->capacity) {
		int* ptemp = (int*)realloc(t->head, t->size * 2 * sizeof(int)); // ʹ��realloc���ڴ���������
		if (!ptemp) {
			printf("Failed!");
			return;
		}
		t->head = ptemp;
		t->capacity = t->size * 2;
	}
	for (int i = t->size; i > pos; --i) {
		t->head[i] = t->head[i - 1];
	}
	t->head[pos] = elem;
	t->size++;
}
/**
*	@brief	��������ɾ��Ԫ��
*	@param	table* t �����ַ, int pos ����
*	@retval None
*/
void delTable(array_Node* t, int pos) {
	if (pos >= t->size || pos < 0) {
		return;
	}
	for (int i = pos; i < t->size; ++i) {
		t->head[i] = t->head[i + 1];
	}
	t->size--;
}
/**
*	@brief	���������Ԫ��(�������ظ�Ԫ��)
*	@param	table* t �����ַ, int elem ������Ԫ��
*	@retval ����ҵ���������ֵ�����û�ҵ�����-1
*/
int selectTable(array_Node* t, int elem) {
	for (int i = 0; i < t->size; ++i) {
		if (t->head[i] == elem) {
			return i;
		}
	}
	return -1;
}
/**
*	@brief	���������ֵ
*	@param	table* t �����ַ, int elem ������Ԫ��, int new_elem ���滻Ԫ��
*	@retval None
*/
void amendTable(array_Node* t, int elem, int new_elem) {
	int index = selectTable(t, elem);
	if (index == -1) {
		return;
	}
	t->head[index] = new_elem;
}