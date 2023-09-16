#include "menu.h"
#include "game.h"
#include <stdio.h>
#include<conio.h>
#include<Windows.h>
/*
	菜单中所包含的变量
*/


const char Border = '#';           //边界的样式
char map_Border[H][L];             //存储地图边界
char key;               //用户输入

/*
	打印一个边框
*/
static void printBorder()
{
	gotoXY(25, 1);
	for (int i = 0; i < L; ++i) putchar(Border);
	gotoXY(25, H);
	for (int i = 0; i < L; ++i)putchar(Border);
	gotoXY(25, 2);
	for (int i = 0; i < H-2; ++i) {
		putchar(Border);
		for (int i = 0; i < L - 2; ++i)putchar(' ');
		putchar(Border);
		gotoXY(25, 3 + i);
	}
	gotoXY(26, 2);
}
/*
	打印游戏菜单函数
*/

void printMenu()
{
	printBorder();
	int userChoose = 0;      //用户当前选择
	while (1) {
		gotoXY(57, 7);
		printf("贪吃蛇");
		if (userChoose == 0)setPrintcolor(0x6f);//设置背景高亮
		gotoXY(56, 9);
		printf("开始游戏");
		setPrintcolor(0x0f);  //恢复背景颜色(黑色)
		if (userChoose == 1)setPrintcolor(0x6f);
		gotoXY(56, 10);
		printf("游戏设置");
		setPrintcolor(0x0f);
		if (userChoose == 2)setPrintcolor(0x6f);
		gotoXY(56, 11);
		printf("排行榜");
		setPrintcolor(0x0f);
		if (userChoose == 3)setPrintcolor(0x6f);
		gotoXY(56, 12);
		printf("退出游戏");
		setPrintcolor(0x0f);

		key = _getch();         //从键盘上获取用户输入
		userInput(key,&userChoose);
		//system("pause");
	}
}

/*
	将光标传递到指定位置
*/
void gotoXY(int x,int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/*
	设置控制台的颜色
*/
void setPrintcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
/*
	获取用户键盘输入
*/
static void userInput(char input, int* userChoose)
{
	switch (input) {
	case 'W':
	case 'w':
		(*userChoose) -= 1;
		if (*userChoose == -1) *userChoose = 3;
		break;
	case 'S':
	case 's':
		(*userChoose) = (*userChoose + 1) % 4;
		break;
	case '\r':
		clear(26, 2, 68, 28);
		switch (*userChoose) {
		case 0:
			// Start game
			clear(26, 2, 68, 28);
			gameView();         //开始游戏界面
			system("pause");
			break;
		case 1:
			clear(26, 2, 68, 28);
			// Setting
			// setting();
			system("pause");
			break;
		case 2:
			clear(26, 2, 68, 28);
			// Show rank
			// showRank();
			system("pause");
			break;
		case 3:
			clear(26, 2, 68, 28);
			gotoXY(26, 2);
			printf("\t\t\t\t感谢您的使用!!!");
			exit(0);
		}
	}
}


/*
	清理指定矩形区域从（x，y）到（x+w，y+h）
*/

void clear(int x, int y, int w, int h)
{
	for (int i = 0; i < h; ++i) {
		gotoXY(x, y + i);   //将光标移动到x,y+i的位置
		for (int j = 0; j < w; ++j)putchar(' ');
	}
}
