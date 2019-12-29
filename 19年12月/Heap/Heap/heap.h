typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);
//�����ն�
void HeapInit(Heap* hp);
void ShiftDown(HPDataType* a, int n,int root);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
// ��������ж�����
void HeapSort(int* a, int n);  