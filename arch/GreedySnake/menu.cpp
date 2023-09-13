#include "menu.h"
#include <stdio.h>
#include<conio.h>
#include<Windows.h>


/*
	菜单中所需的数据
*/

const int H = 30;         //游戏窗口的宽
const int L = 70;           //游戏窗口的长
const char Border = '#';           //边界的样式
char map_Border[H][L];             //存储地图边界


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

		getchar();
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
void userInput(char input)
{
	switch (input) {

	}
}
