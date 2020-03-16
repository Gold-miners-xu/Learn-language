#include<stdio.h>
#include<string.h>
typedef struct PersonInfo {
	char name[1024];
	char tel[1024];

} PersonInfo;

typedef struct Contact {
	PersonInfo con[200];
	int size;

} Contact;

void Init(Contact* addressBook) {
	addressBook->size = 0;
	for (int i = 0; i < 200; i++) {
		strcpy(addressBook->con[i].name, "");
		strcpy(addressBook->con[i].tel, "");
	}
	return;
}

int main() {
	Contact addressBook;
	Init(&addressBook);


	return 0;
}
