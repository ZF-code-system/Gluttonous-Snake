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
void printBorder()
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
	将光标传递到制定位置
*/
void gotoXY(int x,int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
