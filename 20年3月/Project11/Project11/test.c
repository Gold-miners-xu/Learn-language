#include<stdio.h>

void* Memcpy(void* dest, void* src, long num) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	void* rit = dest;
	long i = 0;
	while (i < num) {
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src)++;
		i++;
	}
	return rit;
}
void* Memmove(void* dest, void* src, long num) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	void* rit = dest;
	if (src > dest && (char*)dest > (char*)src + num) {
		Memcpy(dest, src, num);
	}
	else {
		(char*)src += (num - 1);
		(char*)dest += (num - 1);
		for (long i = 0; i < num; i++) {
			*(char*)dest = *(char*)src;
			((char*)dest)--;
			((char*)src)--;
		}
	}
	return rit;
}
int main() {
	char a[] = "i like";
	char b[8];
	//Memcpy(b, a, 7);
	Memmove(b, a, 7);
	printf("%s", b);
	return 0;
}