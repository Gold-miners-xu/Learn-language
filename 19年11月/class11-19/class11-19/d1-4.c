//�ݹ�ʵ���ַ�������
#include <stdio.h>
#include <string.h>
void reverse(char* str)
{
	int len = strlen(str);
	if (len > 1)
	{
		char temp = str[0];
		str[0] = str[len - 1];
		str[len - 1] = '\0';//���һ���ַ����´εݹ�ʱ���ٴ���
		reverse(str + 1);//�ݹ����
		str[len - 1] = temp;
	}
	
}

int main()
{
	char str[100];
	printf("�������ַ�����\n");
	gets(str);
	reverse(str);
	puts(str);
	return 0;
}