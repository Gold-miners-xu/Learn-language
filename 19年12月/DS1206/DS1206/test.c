#include<stdio.h>
#include<stdlib.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	if (m == 0) {
		for (int k = 0; k < n; k++) {
			nums1[k] = nums2[k];
		}
	}
	else
		for (int i = 0; i < nums1Size; i++) {
			if (i < m)
				for (int j = 0; j < nums2Size; j++) {

					if (nums1[i] > nums2[j]) {
						int tmp;
						tmp = nums1[i];
						nums1[i] = nums2[j];
						nums2[j] = tmp;
					}
					if ((j < n - 1) && (nums2[j] > nums2[j + 1])) {
						int tmp = nums2[j];
						nums2[j] = nums2[j + 1];
						nums2[j + 1] = tmp;
					}

				}
			else {
				nums1[i] = nums2[i - m];
			}
		}
}//合并有序数组
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
	if (K == 0) {
		*returnSize = ASize;
		return A;
	}
	else {
		int KSize = 0;
		int* a;
		for (int i = K; i != 0; i /= 10)
			KSize++;
		if (ASize > KSize) {
			a = calloc(ASize + 1, sizeof(int));
			*returnSize = ASize + 1;
		}
		else {
			a = calloc(KSize + 1, sizeof(int));
			*returnSize = KSize + 1;
		}
		for (int size = *returnSize - 1; size >= 0; size--, ASize--) {
			int next;
			if (ASize <= 0) {
				a[size] = K % 10;
			}
			else if ((K % 10) + A[ASize - 1] > 9) {
				a[size] += (K % 10 + A[ASize - 1]) % 10;
				a[size - 1] = 1;
				K /= 10;
			}
			else {
				a[size] += K % 10 + A[ASize - 1];
				K /= 10;
			}
		}
		if (a[0] == 0) {
			*returnSize = *returnSize - 1;
			return a + 1;
		}
		return a;
	}
}
int main() {
	int a[4] = { 2,1,5 };
	int b[5] = { 1,2,3,5,6 };
	//merge(a, 5, 1, b, 5, 5);
	int size = 1;
	int* s;
	s = addToArrayForm(a, 3, 806, &size);
	return 0;
}
/*
指针运算:
指针+整数->指针+1:相当于地址向后跳过一个元素
           指针-1:相当于向前跳过一个元素
指针-指针->本质上是在算指针之间隔了几个元素
指针相减有意义:(1)两个指针类型相同
			   (2)两个指针必须指向同一个连续内存空间
void*不能进行指针运算
指针关系运算
指针比较大小,一般没有意义,
保证前提:
1>指针类型相同
2>指针指向同一个相同连续空间
指针比较是否相等:



C语言中比较两个字符串:
1>"=="比较两个字符串的身份/地址
2>strcmp比较字符串内容
strcmp(字典序)
const和指针搭配
const int* p 限制指针指向地址对应元素
int const * p 限制指针指向地址对应元素
int* const p 限制指针指向
*/