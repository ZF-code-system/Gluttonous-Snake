#include "menu.h"
#include <stdio.h>
#include<conio.h>
#include<Windows.h>


/*
	�˵������������
*/

const int H = 30;         //��Ϸ���ڵĿ�
const int L = 70;           //��Ϸ���ڵĳ�
const char Border = '#';           //�߽����ʽ
char map_Border[H][L];             //�洢��ͼ�߽�




/*
	��ӡһ���߿�
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
	����괫�ݵ��ƶ�λ��
*/
void gotoXY(int x,int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
