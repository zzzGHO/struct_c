#ifndef __ARRAY_H__
#define __ARRAY_H__
typedef struct arrNode {
	int* head;		// 声明长度未定的数组
	int size;		// 数组的长度
	int capacity;	// 数组的容量
}array_Node;
array_Node* initArray(int n);
void amendTable(array_Node* t, int elem, int new_elem);
int selectTable(array_Node* t, int elem);
void delTable(array_Node* t, int pos);
void addTable(array_Node* t, int elem, int pos);
void print_array(array_Node* t);
#endif