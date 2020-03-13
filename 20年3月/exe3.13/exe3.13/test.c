#include <stdio.h>
union Un
{
	short s[7];
	int n;
};
//int main()
//{
//	printf("%d\n", sizeof(union Un));
//	return 0;
//}
int main()
{
	//union
	//{
	//	short k;
	//	char i[2];
	//}*s, a;
	//s = &a;
	//s->i[0] = 0x39;
	//s->i[1] = 0x38;
	//printf(" % x\n", a.k);

	enum ENUM_A
	{
		X1,
		Y1,
		Z1 = 255,
		A1,
		B1,
	};
	enum ENUM_A enumA = Y1;
	enum ENUM_A enumB = B1;
	printf("%d %d\n", enumA, enumB);
	return 0;
}