#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<string.h>
#define MAX_SIZE 200
typedef struct PersonInfo {
	char name[1024];
	char tel[1024];

} PersonInfo;

typedef struct Contact {
	PersonInfo con[200];
	int size;

} Contact;
//��ʼ���ṹ�� 
void Init(Contact* addressBook) {
	addressBook->size = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		strcpy(addressBook->con[i].name, "");
		strcpy(addressBook->con[i].tel, "");
	}
	return;
}
//��ȡ�ļ�����
void load(Contact* addressBook) {
	FILE* fp = fopen("D:/test.txt","r");
	if (fp == NULL) {
		printf("��ȡʧ��\n");
		return;
	}
	PersonInfo tmp = { 0 };
	while (1) {
		int n = fread(&tmp, sizeof(PersonInfo), 1, fp);
		if (n < 1) {
			break;
		}
		addressBook->con[addressBook->size] = tmp;
		addressBook->size++;
	}
	fclose(fp);
}
//д���ļ�
void save(const Contact* addressBook) {
	FILE* fp = fopen("D:/test.txt", "w");
	if (fp == NULL) {
		printf("���ļ�ʧ��\n");
		return;
	}
	for (int i = 0; i < addressBook->size; i++) {
		fwrite(&addressBook->con[i], sizeof(PersonInfo), 1, fp);
	}
	fclose(fp);
}
void Add(Contact* addressBook) {
	printf("������ϵ��\n");
	if (addressBook->size >= MAX_SIZE) {
		printf("��ϵ�˴洢���Ѵ����,����ʧ��\n");
		return;
	}
	printf("������������ϵ������\n");
	scanf("%s", &addressBook->con[addressBook->size].name);
	printf("������������ϵ�˵绰\n");
	scanf("%s", &addressBook->con[addressBook->size].tel);
	addressBook->size++;
	printf("������ϵ�˳ɹ�\n");
}

void Print(Contact* addressBook) {
	printf("��ӡȫ����ϵ��\n");
	for (int i = 0; i < addressBook->size; i++) {
		printf(" [%d] : %s  ", i + 1,addressBook->con[i].name);
		printf("%s\n", addressBook->con[i].tel);
	}

}

void Del(Contact* addressBook) {
	printf("ɾ����ϵ��\n");
	if (addressBook->size < 1) {
		printf("����ϵ��,ɾ��ʧ��\n");
		return;
	}
	printf("������Ҫɾ�������\n");
	int ID;
	scanf("%d", &ID);
	if (ID < 0 || ID > addressBook->size) {
		printf("��ų�����Χ,ɾ��ʧ��\n");
		return;
	}
	addressBook->con[ID] = addressBook->con[addressBook->size - 1];
	addressBook->size--;
	printf("ɾ���ɹ�\n");

}

void Find(Contact* addressBook) {
	printf("������ϵ��\n");
	printf("�����������ϵ������\n");
	char a[100] = { 0 };
	scanf("%s", a);
	for (int i = 0; i < addressBook->size; i++) {
		if (strcmp(a, &addressBook->con[i].name) == 0) {
			printf("%s   ", addressBook->con[i].name);
			printf("%s\n", addressBook->con[i].tel);
		}
	}
	printf("�������\n");
}

void Modi(Contact* addressBook) {
	printf("�޸���ϵ��\n");
	if (addressBook->size < 1) {
		printf("����ϵ��,�޸�ʧ��\n");
		return;
	}
	printf("������Ҫ�޸ĵ����\n");
	int ID;
	scanf("%d", &ID);
	if (ID < 0 || ID > addressBook->size) {
		printf("��ų�����Χ,�޸�ʧ��\n");
		return;
	}
	printf("�������޸ĺ������\n");
	scanf("%s", &addressBook->con[ID].name);
	printf("�������޸ĺ�ĵ绰\n");
	scanf("%s", &addressBook->con[ID].tel);
	printf("�޸ĳɹ�\n");
}

void Clear(Contact* addressBook) {
	printf("���������ϵ��\n");
	printf("�Ƿ�ɾ��������ϵ��?\ny/n\n");
	char a;
	scanf("%c", &a);
	if (a == 'y') {
		addressBook->size = 0;
		printf("ɾ���ɹ�\n");
	}
	else {
		printf("ɾ��ʧ��");
		return;
	}
}
int Menu() {
	printf("=======================================\n");
	printf("1. ������ϵ��\n");
	printf("2. ɾ����ϵ��\n");
	printf("3. ������ϵ��\n");
	printf("4. �޸���ϵ��\n");
	printf("5. ��ӡȫ����ϵ��\n");
	printf("6. ���ȫ����ϵ��\n");
	printf("0. �˳�\n");
	printf("======================================\n");
	printf("����������ѡ��\n");
	int a = 0;
	scanf("%d", &a);
	return a;
}
int main() {
	Contact addressBook;
	Init(&addressBook);
	load(&addressBook);
	while (1) {
		int choice = Menu();
		if (choice == 0) {
			save(&addressBook);
			break;
		}
		if (choice == 1) {
			Add(&addressBook);
		}
		if (choice == 2) {
			Del(&addressBook);
		}
		if (choice == 3) {
			Find(&addressBook);
		}
		if (choice == 4) {
			Modi(&addressBook);
		}
		if (choice == 5) {

			Print(&addressBook);
		}
		if (choice == 6) {
			Clear(&addressBook);
		}

	}
	printf("bye\n");

	return 0;
}
