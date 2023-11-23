#include <stdio.h>
#include <stdlib.h>	// malloc需要
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
  * @brief  在数组中插入数据
  * @param  table* t 数组地址, int elem 插入数据, int pos 插入索引(位置)
  * @retval None
  */
void addTable(array_Node* t, int elem, int pos) {
	if (pos > t->size || pos < 0) {		// 超出数组范围或索引不合理
		return;
	}
	if (t->size == t->capacity) {
		int* ptemp = (int*)realloc(t->head, t->size * 2 * sizeof(int)); // 使用realloc将内存扩大两倍
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
*	@brief	从数组中删除元素
*	@param	table* t 数组地址, int pos 索引
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
*	@brief	从数组查找元素(不考虑重复元素)
*	@param	table* t 数组地址, int elem 待查找元素
*	@retval 如果找到返回索引值，如果没找到返回-1
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
*	@brief	从数组更换值
*	@param	table* t 数组地址, int elem 待查找元素, int new_elem 待替换元素
*	@retval None
*/
void amendTable(array_Node* t, int elem, int new_elem) {
	int index = selectTable(t, elem);
	if (index == -1) {
		return;
	}
	t->head[index] = new_elem;
}