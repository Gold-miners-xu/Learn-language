//递归实现字符串倒置
#include <stdio.h>
#include <string.h>
void reverse(char* str)
{
	int len = strlen(str);
	if (len > 1)
	{
		char temp = str[0];
		str[0] = str[len - 1];
		str[len - 1] = '\0';//最后一个字符在下次递归时不再处理
		reverse(str + 1);//递归调用
		str[len - 1] = temp;
	}
	
}

int main()
{
	char str[100];
	printf("请输入字符串：\n");
	gets(str);
	reverse(str);
	puts(str);
	return 0;
}