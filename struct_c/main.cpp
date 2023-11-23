#include <stdio.h>
#include "dep/array.h"
#include "dep/staticList.h"
#include "dep/dynamic_list.h"
#include "dep/double_list.h"
#include "dep/circular_list.h"


void Josephus(int n, int m);

int main() {
	array_Node* arr = initArray(5);
	addTable(arr, 2, 0);
	addTable(arr, 4, 1);
	addTable(arr, 5, 2);
	addTable(arr, 9, 3);
	print_array(arr);
	static_list list;
	InitStaticList(&list);
	push_static_list(&list, 5);
	push_static_list(&list, 6);
	push_static_list(&list, 7);
	print_static_list(&list);
	pop_static_list(&list);
	print_static_list(&list);
	
	dynamic_List* head = InitDynamicList();
	push_dynamic_list(head, 6);
	push_dynamic_list(head, 7);
	push_dynamic_list(head, 8);
	print_dynamic_list(head);
	pop_dynamic_list(head);
	print_dynamic_list(head);
	
	double_List* head2 = InitDoubleList();
	push_front_double_list(head2, 3);
	push_front_double_list(head2, 2);
	push_front_double_list(head2, 1);
	push_back_double_list(head2, 4);
	print_front_double_list(head2);
	pop_front_double_list(head2);
	pop_back_double_list(head2);
	print_front_double_list(head2);
	
	
	Circular_List* head3 = InitCircularList();
	push_front_circular_list(head3, 3);
	push_front_circular_list(head3, 2);
	push_front_circular_list(head3, 1);
	push_back_circular_list(head3, 4);
	push_back_circular_list(head3, 5);
	push_back_circular_list(head3, 6);
	print_front_circular_list(head3, 15);
	
	return 0;
}


void Josephus(int n, int m) {
	Circular_List* head = InitCircularList();
	for (int i = 1; i <= n; ++i) {
		push_back_circular_list(head, i);
	}
	int num = 1;
	int loop = 1;
	circular_ListNode* temp = head->pNext;
	circular_ListNode* next = temp;
	printf("第%d轮剩余的人%d：", loop, size_circular_list(head));
	print_front_circular_list(head, size_circular_list(head));
	while (size_circular_list(head) != 1) {
		if (num % m == 0) {
			next = temp->pNext;
			pop_circular_list(head, temp);
			printf("第%d轮剩余的人%d：", loop, size_circular_list(head));
			print_front_circular_list(head, size_circular_list(head));
			temp = next;
			num = 0;
		}
		else {
			temp = temp->pNext;
		}
		num++;
		loop++;

	}
}
