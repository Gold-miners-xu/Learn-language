#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define ROW 9
#define COL 9
//1.����������ͼ,��ʼ��
//2.��ӡ��ͼ(showMap),ʹ�ö���ѭ��,��ӡ��ά����
//3.��ʾ�����������,��У��.void (int* row,int* col)
//4.��鵱ǰλ���Ƿ�Ϊ��
//5.�ж���Ϸ�Ƿ�ʤ��,���㷭�����ӵ�����
//6.��������*�滻������
int Menu() {
	printf("*****************\n");
	printf("������ѡ��ǰ�����\n");
	printf("   1.��ʼ��Ϸ\n");
	printf("   0.�˳���Ϸ\n");
	printf("*****************\n");
	int x;
	scanf("%d", &x);
	if (x < 0 && x>1) {
		printf("��������,����������\n");
		Menu();
	}
	return x;
}
void Initialize(char showMap[ROW][COL], char mainMap[ROW][COL]) {
	memset(showMap, '*', ROW * COL);
	memset(mainMap, '1', ROW * COL);
	int row, col;
	for (int i = 0; i < 10; i++) {
		row = rand() % 9;
		col = rand() % 9;
		if (mainMap[row][col] != '0') {
			mainMap[row][col] = '0';
			continue;
		}
		i--;
	}
}
void Print(char Map[ROW][COL]) {
	printf("  | 0 1 2 3 4 5 6 7 8 \n");
	printf("--+------------------\n");
	for (int row = 0; row < ROW; row++) {
		printf(" %d|", row);
		for (int col = 0; col < COL; col++) {
			printf(" %c", Map[row][col]);
		}
		printf("\n");
	}
}
void Player(int* row,int* col,char showMap[ROW][COL]) {
	printf("�����������Ҫ����λ�õ�����\n");
	for (; 1;) {
		scanf("%d %d", row, col);
		if (*row < 0 || *row > 8 || *col < 0 || *col > 8) {
			printf("������������,����������\n");
			continue;
		}
		int r = *row;
		int c = *col;
		if (showMap[r][c] != '*') {
			printf("��λ���ѱ�����,����������\n");
			continue;
			
		}
		return;
	}

}
int Check(int* row, int* col, char mainMap[ROW][COL],
	char showMap[ROW][COL]) {
	if (mainMap[*row][*col] == '0')
		return 1;
	int cont = 0;
	for (int r = 0; r < ROW; r++)
		for (int c = 0; c < COL; c++) {
			if(showMap[r][c] != '*')
			cont++;
		}
	return cont;
}
void Replace(char showMap[ROW][COL],char mainMap[ROW][COL],
	int row, int col) {
	if (mainMap[row][col] == '0')
		return;
	int sum = 0;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (c < 0 || c >= ROW || r < 0 || r >= COL)
				continue;
			if (mainMap[r][c] == '0')
				sum++;				
		}
	}
	if (sum == 0)
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (c < 0 || c >= ROW || r < 0 || r >= COL)
				continue;
			if (showMap[r][c] == ' ')
				continue;
			showMap[row][col] = ' ';
		    Replace(showMap, mainMap, r, c);
				
		}
	}
	else
	{
		showMap[row][col] = sum + '0';
		return;
	}
}
void Game() {
	char showMap[ROW][COL];
	char mainMap[ROW][COL];
	srand((unsigned)time(0));
	Initialize(showMap, mainMap);
	Print(showMap);
	int row;
	int col;
	for (; 1;) {
		Player(&row, &col, showMap);
		if (Check(&row, &col, mainMap,showMap) == 1) {
			printf("������\n");
			Print(mainMap);
			return;
		}
		Replace(showMap, mainMap, row, col);
		Print(showMap);
		if (Check(&row, &col, mainMap, showMap) == 71) {
			printf("��ϲ��,��Ӯ��\n");
			Replace(showMap, mainMap, row, col);
			Print(showMap);
			return;
		}
		
	}
}
int main() {
	
	for (; Menu();) {
		Game();
	}
	printf("byebye\n");
	return 0;
}