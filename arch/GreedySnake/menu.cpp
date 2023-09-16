#include "menu.h"
#include <stdio.h>
#include<conio.h>
#include<Windows.h>
/*
	�˵����������ı���
*/
const int H = 30;         //��Ϸ���ڵĿ�
const int L = 70;           //��Ϸ���ڵĳ�
const char Border = '#';           //�߽����ʽ
char map_Border[H][L];             //�洢��ͼ�߽�
char key;               //�û�����
int userChoose = 0;     //�û���ǰѡ��ʼ��Ϸ 

/*
	��ӡһ���߿�
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
	��ӡ��Ϸ�˵�����
*/

void printMenu()
{
	printBorder();
	userChoose = 0;      //�û���ǰѡ��
	while (1) {
		gotoXY(57, 7);
		printf("̰����");
		if (userChoose == 0)setPrintcolor(0x6f);//���ñ�������
		gotoXY(56, 9);
		printf("��ʼ��Ϸ");
		setPrintcolor(0x0f);  //�ָ�������ɫ(��ɫ)
		if (userChoose == 1)setPrintcolor(0x6f);
		gotoXY(56, 10);
		printf("��Ϸ����");
		setPrintcolor(0x0f);
		if (userChoose == 2)setPrintcolor(0x6f);
		gotoXY(56, 11);
		printf("���а�");
		setPrintcolor(0x0f);
		if (userChoose == 3)setPrintcolor(0x6f);
		gotoXY(56, 12);
		printf("�˳���Ϸ");
		setPrintcolor(0x0f);

		key = _getch();         //�Ӽ����ϻ�ȡ�û�����
		userInput(key);
	}
}

/*
	����괫�ݵ�ָ��λ��
*/
void gotoXY(int x,int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/*
	���ÿ���̨����ɫ
*/
void setPrintcolor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
/*
	��ȡ�û���������
*/
static void userInput(char input)
{
	switch (input) {
	case 'W':
	case 'w':
		userChoose -= 1;
		if (userChoose == -1)userChoose = 3;
		break;
	case 'S':
	case 's':
		userChoose = (userChoose + 1) % 4;
		break;
	case '\r':
		clear(26,2,68,28);
		switch (userChoose) {
		case '0':
			//clear(26, 2, 68, 28);
			//gameview();         //��ʼ��Ϸ
			system("pause");
			break;
		case '1':
			clear(26, 2, 68, 28);
			//setting();          //������Ϸ��Ч
		case '2':
			clear(26, 2, 68, 28);
			//showRank();         //��ʷ���а�
		case '3':
			clear(26, 2, 68, 28);
			gotoXY(26, 2);
			printf("\t��л����ʹ��");
			system("pause");
			break;
		}
		break;
	default:
		break;
	}
}

/*
	����ָ����������ӣ�x��y������x+w��y+h��
*/

void clear(int x, int y, int w, int h)
{
	for (int i = 0; i < h; ++i) {
		gotoXY(x, y + i);   //������ƶ���x,y+i��λ��
		for (int j = 0; j < w; ++j)putchar(' ');
	}
}
