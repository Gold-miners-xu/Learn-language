#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define LINE 3
#define COL 3



int Face() {
	//��ӡ��Ϸ����
	printf("----------------------\n");
	printf("-------1.��ʼ��Ϸ-----\n");
	printf("-------0.�˳���Ϸ-----\n");
	printf("----------------------\n");
	int x = 0;
	scanf("%d", &x);
	return x;
}
void Print(char tacTic[LINE][COL]) {
	for (int line = 0; line < LINE; line++) {
		
		printf("+---+---+---+\n");
		printf("| %c | %c | %c |\n",
			tacTic[line][0], tacTic[line][1], tacTic[line][2]);
	}
	printf("+---+---+---+\n");
}
void Player(char tacTic[LINE][COL]) {
	printf("���������\n");
	int line, col;
	for (; 1;) {
		scanf("%d %d", &line, &col);
		
		if (line > 2 || line < 0 ||
			col>2 || col < 0) {
			printf("������������,����������\n");
			continue;
		}
		if (tacTic[line][col] != ' ') {
				printf("��λ���Ѿ�����,����������\n");
				continue;
		}
		
		tacTic[line][col] = 'x';
		break;
	}
}
void CmpPly(char tacTic[LINE][COL]) {
	for (; 1;) {
		int line = rand() % 3;
	    int col = rand() % 3;
		if (tacTic[line][col] != ' ') 
			continue;
		tacTic[line][col] = '0';
		break;
	}
}
char Search(char tacTic[LINE][COL]) {
	//������
	int line = 0;
	int col = 0;
	for (; line < LINE; line++) {
		if (tacTic[line][0] == tacTic[line][1] &&
			tacTic[line][0] == tacTic[line][2]) {
			return tacTic[line][0];
		}
	}
	//������
	for (; col < COL; col++) {
		if (tacTic[0][col] == tacTic[1][col] &&
			tacTic[0][col] == tacTic[2][col]) {
			return tacTic[0][col];
		}
	}
	//���ҶԽ���
	if (tacTic[0][0] == tacTic[1][1] &&
		tacTic[0][0] == tacTic[2][2])
		return tacTic[0][0];
	if (tacTic[0][2] == tacTic[1][1] &&
		tacTic[0][2] == tacTic[2][0])
		return tacTic[1][1];
	//�鿴�����Ƿ�����
	for (line = 0; line < LINE; line++) {
		for (col = 0; col < COL; col++) {
			if (tacTic[line][col] == ' ')
				return 'y';
		}
	}
	return 'q';
}
void Game() {
	char tacTic[LINE][COL];
	//��ʼ������
	memset(tacTic, ' ', LINE * COL);
	srand((unsigned)time(NULL));
	 //��ӡ����
	for (; 1;) {
		Print(tacTic);
		Player(tacTic);
		//�����Ϸ�Ƿ����
		char search = Search(tacTic);
		if (search == 'x') {
			Print(tacTic);
			printf("��ϲ��,��Ӯ��\n");
			return;
		}
		if (search == '0') {
			Print(tacTic);
			printf("������,��Ϸ����\n");
			return;
		}
		if (search == 'q') {
			Print(tacTic);
			printf("����\n");
			return;
		}
		//��������
		CmpPly(tacTic);
		//����Ƿ�����Ծ�
		search = Search(tacTic);
		if (search == 'x') {
			Print(tacTic);
			printf("��ϲ��,��Ӯ��\n");
			return;
		}
		if (search == '0') {
			Print(tacTic);
			printf("������,��Ϸ����\n");
			return;
		}
		if (search == 'q') {
			Print(tacTic);
			printf("����\n");
			return;
		}

	}
	
}
int main() {

	while (1) {
		int x = Face();
		if (x == 1) {
			Game();
			continue;
		}
		else if (x == 0)
			break;
		else {
			printf("��������,����������\n");
		}
	}
	printf("byebye\n");
	
	return 0;


}