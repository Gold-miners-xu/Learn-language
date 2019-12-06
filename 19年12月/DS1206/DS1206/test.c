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
}//�ϲ���������
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
ָ������:
ָ��+����->ָ��+1:�൱�ڵ�ַ�������һ��Ԫ��
           ָ��-1:�൱����ǰ����һ��Ԫ��
ָ��-ָ��->������������ָ��֮����˼���Ԫ��
ָ�����������:(1)����ָ��������ͬ
			   (2)����ָ�����ָ��ͬһ�������ڴ�ռ�
void*���ܽ���ָ������
ָ���ϵ����
ָ��Ƚϴ�С,һ��û������,
��֤ǰ��:
1>ָ��������ͬ
2>ָ��ָ��ͬһ����ͬ�����ռ�
ָ��Ƚ��Ƿ����:



C�����бȽ������ַ���:
1>"=="�Ƚ������ַ��������/��ַ
2>strcmp�Ƚ��ַ�������
strcmp(�ֵ���)
const��ָ�����
const int* p ����ָ��ָ���ַ��ӦԪ��
int const * p ����ָ��ָ���ַ��ӦԪ��
int* const p ����ָ��ָ��
*/