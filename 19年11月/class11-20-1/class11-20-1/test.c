#include<stdio.h>
#include<string.h>
int recursive(char* str) {
	int i = 0;
	if (str[i] == '\0')
		return 0;
	return 1+recursive(str + 1);

}//递归函数求字符串长度
int cursive(char* str) {
	int i = 0;
	for (; 1;) {

		if (str[i] == '\0')
			return i;
		else
			i++;
	}
			
		
}//非递归函数求字符串长度
int main() {
	char a[100] = { 0 };//定义一个容量为100的字符数组
	gets(a);
	printf("%d",recursive(a));//调用递归函数求出结果
	gets(a);
	printf("%d", cursive(a));//调用非递归函数得出结果
	return 0;
}