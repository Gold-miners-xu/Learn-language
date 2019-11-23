#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define LINE 3
#define COL 3



int Face() {
	//打印游戏界面
	printf("----------------------\n");
	printf("-------1.开始游戏-----\n");
	printf("-------0.退出游戏-----\n");
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
	printf("请玩家落子\n");
	int line, col;
	for (; 1;) {
		scanf("%d %d", &line, &col);
		
		if (line > 2 || line < 0 ||
			col>2 || col < 0) {
			printf("您的输入有误,请重新输入\n");
			continue;
		}
		if (tacTic[line][col] != ' ') {
				printf("此位置已经有棋,请重新输入\n");
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
	//查找行
	int line = 0;
	int col = 0;
	for (; line < LINE; line++) {
		if (tacTic[line][0] == tacTic[line][1] &&
			tacTic[line][0] == tacTic[line][2]) {
			return tacTic[line][0];
		}
	}
	//查找列
	for (; col < COL; col++) {
		if (tacTic[0][col] == tacTic[1][col] &&
			tacTic[0][col] == tacTic[2][col]) {
			return tacTic[0][col];
		}
	}
	//查找对角线
	if (tacTic[0][0] == tacTic[1][1] &&
		tacTic[0][0] == tacTic[2][2])
		return tacTic[0][0];
	if (tacTic[0][2] == tacTic[1][1] &&
		tacTic[0][2] == tacTic[2][0])
		return tacTic[1][1];
	//查看棋盘是否下满
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
	//初始化棋盘
	memset(tacTic, ' ', LINE * COL);
	srand((unsigned)time(NULL));
	 //打印棋盘
	for (; 1;) {
		Print(tacTic);
		Player(tacTic);
		//检查游戏是否结束
		char search = Search(tacTic);
		if (search == 'x') {
			Print(tacTic);
			printf("恭喜你,你赢了\n");
			return;
		}
		if (search == '0') {
			Print(tacTic);
			printf("你输了,游戏结束\n");
			return;
		}
		if (search == 'q') {
			Print(tacTic);
			printf("和棋\n");
			return;
		}
		//电脑落子
		CmpPly(tacTic);
		//检查是否结束对局
		search = Search(tacTic);
		if (search == 'x') {
			Print(tacTic);
			printf("恭喜你,你赢了\n");
			return;
		}
		if (search == '0') {
			Print(tacTic);
			printf("你输了,游戏结束\n");
			return;
		}
		if (search == 'q') {
			Print(tacTic);
			printf("和棋\n");
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
			printf("输入有误,请重新输入\n");
		}
	}
	printf("byebye\n");
	
	return 0;


}