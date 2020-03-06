#include<stdio.h>

struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
};

int main() {
	// 问题1
	//int a[5] = { 1, 2, 3, 4, 5 };

	//int* ptr = (int*)(&a + 1);
	//// 2 5
	//printf("%d,%d", *(a + 1), *(ptr - 1));  

	/*	首先，从这段代码中可以看到定义了一个长度为5的数组a，然后定义了一个指针ptr，将
	ptr指向（int*）（&a+1），（&a+1）数组名取地址再加1，是跳过整个数组，指向a[4]
	后面的地址，（int*）再将int（*）[5]类型的变量强转为int（*）类型，然后打印
	*（a+1），数组名加1，在C语言中a将强制转换为a[0]的地址意味着数组的首元素地址向
	后跳过一个元素即为a[1]的地址，在解引用打印数字为2，*（ptr-1）则是将ptr指针向前
	跳过sizeof（int）个字节，在解引用，于是打印的结果回事a[4]中的数值，也就是5，
	
	于是此题的答案则为2，5*/

	// 问题2
	//struct Test* p = (struct Test*)0x100000; 
	//printf("%p\n", p + 0x1);
	//printf("%p\n", (unsigned long)p + 0x1);
	//printf("%p\n", (unsigned int*)p + 0x1);
	
	/*	题中的代码给出一个结构体，并定义了一个指向该结构体的指针p，p+0x1，可以理解为p+1
	因为0x1本就是16进制中的1，指针加1就等于指针向后跳过指针所指向类型的字节数，这里
	根据结构体中的内容可知此结构体大小为20个字节，所以p+0x1 = 0x100020，
	(unsigned long)p + 0x1这里是将p强制转换为unsigned long类型，再加一，就得到
	一个unsigned long类型的整数，用16进制表示为0x100001
	(unsigned int*)p + 0x1最后一个问题是将p强制转换为unsigned int*类型的变量，
	再加1，指针加一就跳过sizeof（unsigned int*）个字节，也就是4个字节，这里答案为
	0x100004*/

	// 问题3
	//int a[4] = { 1, 2, 3, 4 };
	//int *ptr1 = (int *)(&a + 1);
	//int *ptr2 = (int *)((int)a + 1);
	//printf("%x,%x", ptr1[-1], *ptr2);

	// 问题4
	// 长度为 3 个元素的一维数组, 每个元素长度为 2  => 1
	// 长度为 2 个元素的一维数组, 每个元素长度为 3  => 2
	// int a[3][2] = { {0, 1}, {2, 3}, {4, 5} }
	//int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	//int *p;
	//// a[0] 取到了一个长度为 2 个元素的一维数组
	//// p 是当前这个数组的首元素地址
	//p = a[0];
	//// 0???
	//printf("%d", a[0][0]);

	// 问题5
	//int a[5][5];	// 二维数组
	//int(*p)[4];		// 数组指针
	//p = a;
	//printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);

	// 问题6
	//int aa[2][5] = { 
	//	{1, 2, 3, 4, 5},
	//	{6, 7, 8, 9, 10 } 
	//};
	//// &aa 应该是一个数组指针 int(*)[2][5], 再 + 1 应该要跳过整个数组
	//int *ptr1 = (int *)(&aa + 1);
	//// aa 是二维数组名 再 + 1, 隐式转成 int(*)[5]
	//// int *ptr2 = (int *)(*(aa + 1));
	//int *ptr2 = (int *)(aa[1]);
	//// 10   5
	//printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));

	// 问题 7
	// 指针数组
	//char *a[] = { "work","at","alibaba" };
	//char**pa = a;
	//pa++;
	//printf("%s\n", *pa);

	// 问题 8
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;

	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);

	// cpp[-2] => *(cpp-2) 这个操作没有修改 cpp 的内容. 而上面的 ++ 操作修改 cpp 
	printf("%s\n", *cpp[-2] + 3);
	//printf("%s\n", cpp[-1][-1] + 1);

	system("pause");
	return 0;
}