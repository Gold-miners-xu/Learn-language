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
//初始化结构体 
void Init(Contact* addressBook) {
	addressBook->size = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		strcpy(addressBook->con[i].name, "");
		strcpy(addressBook->con[i].tel, "");
	}
	return;
}
//读取文件内容
void load(Contact* addressBook) {
	FILE* fp = fopen("D:/test.txt","r");
	if (fp == NULL) {
		printf("读取失败\n");
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
//写入文件
void save(const Contact* addressBook) {
	FILE* fp = fopen("D:/test.txt", "w");
	if (fp == NULL) {
		printf("打开文件失败\n");
		return;
	}
	for (int i = 0; i < addressBook->size; i++) {
		fwrite(&addressBook->con[i], sizeof(PersonInfo), 1, fp);
	}
	fclose(fp);
}
void Add(Contact* addressBook) {
	printf("新增联系人\n");
	if (addressBook->size >= MAX_SIZE) {
		printf("联系人存储量已达最大,新增失败\n");
		return;
	}
	printf("请输入新增联系人姓名\n");
	scanf("%s", &addressBook->con[addressBook->size].name);
	printf("请输入新增联系人电话\n");
	scanf("%s", &addressBook->con[addressBook->size].tel);
	addressBook->size++;
	printf("新增联系人成功\n");
}

void Print(Contact* addressBook) {
	printf("打印全部联系人\n");
	for (int i = 0; i < addressBook->size; i++) {
		printf(" [%d] : %s  ", i + 1,addressBook->con[i].name);
		printf("%s\n", addressBook->con[i].tel);
	}

}

void Del(Contact* addressBook) {
	printf("删除联系人\n");
	if (addressBook->size < 1) {
		printf("无联系人,删除失败\n");
		return;
	}
	printf("请输入要删除的序号\n");
	int ID;
	scanf("%d", &ID);
	if (ID < 0 || ID > addressBook->size) {
		printf("序号超出范围,删除失败\n");
		return;
	}
	addressBook->con[ID] = addressBook->con[addressBook->size - 1];
	addressBook->size--;
	printf("删除成功\n");

}

void Find(Contact* addressBook) {
	printf("查找联系人\n");
	printf("请输入查找联系人姓名\n");
	char a[100] = { 0 };
	scanf("%s", a);
	for (int i = 0; i < addressBook->size; i++) {
		if (strcmp(a, &addressBook->con[i].name) == 0) {
			printf("%s   ", addressBook->con[i].name);
			printf("%s\n", addressBook->con[i].tel);
		}
	}
	printf("查找完成\n");
}

void Modi(Contact* addressBook) {
	printf("修改联系人\n");
	if (addressBook->size < 1) {
		printf("无联系人,修改失败\n");
		return;
	}
	printf("请输入要修改的序号\n");
	int ID;
	scanf("%d", &ID);
	if (ID < 0 || ID > addressBook->size) {
		printf("序号超出范围,修改失败\n");
		return;
	}
	printf("请输入修改后的姓名\n");
	scanf("%s", &addressBook->con[ID].name);
	printf("请输入修改后的电话\n");
	scanf("%s", &addressBook->con[ID].tel);
	printf("修改成功\n");
}

void Clear(Contact* addressBook) {
	printf("清空所有联系人\n");
	printf("是否删除所有联系人?\ny/n\n");
	char a;
	scanf("%c", &a);
	if (a == 'y') {
		addressBook->size = 0;
		printf("删除成功\n");
	}
	else {
		printf("删除失败");
		return;
	}
}
int Menu() {
	printf("=======================================\n");
	printf("1. 新增联系人\n");
	printf("2. 删除联系人\n");
	printf("3. 查找联系人\n");
	printf("4. 修改联系人\n");
	printf("5. 打印全部联系人\n");
	printf("6. 清空全部联系人\n");
	printf("0. 退出\n");
	printf("======================================\n");
	printf("请输入您的选择\n");
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
