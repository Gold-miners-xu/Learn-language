#include<stdio.h>
#include<string.h>
int recursive(char* str) {
	int i = 0;
	if (str[i] == '\0')
		return 0;
	return 1+recursive(str + 1);

}//�ݹ麯�����ַ�������
int cursive(char* str) {
	int i = 0;
	for (; 1;) {

		if (str[i] == '\0')
			return i;
		else
			i++;
	}
			
		
}//�ǵݹ麯�����ַ�������
int main() {
	char a[100] = { 0 };//����һ������Ϊ100���ַ�����
	gets(a);
	printf("%d",recursive(a));//���õݹ麯��������
	gets(a);
	printf("%d", cursive(a));//���÷ǵݹ麯���ó����
	return 0;
}