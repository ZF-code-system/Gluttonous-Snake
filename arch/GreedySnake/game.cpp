#include "game.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include<time.h>
#include<Windows.h>

int gameTime = 0;
int score = 0;       //��Ϸ�÷�

int dx = 0;         //ƫ������
int dy = 0;   

int lx = 0;          //��β����
int ly = 0;


struct BODY {
	int x;
	int y;
};

struct _snake {
	int size;
	BODY body[L * H];
}snake;

int food[2] = { 0 };

/*
	��Ϸ����
*/

void gameView()
{
	gameTime = 0;         //��Ϸ��ʱ
	char key = 'D';       //��ʼ����ǰ����Ϊ��           

	while (snake.body[0].x >= 25 && snake.body[0].x < L + 25 && snake.body[0].y >= 0 && snake.body[0].y < H) {
		showMap();

		while (_kbhit()) {//_kbhit()�����жϿ���̨�Ƿ������룬�����������
			key = _getch();//��������ʾ���ռ�������
		}
		//�ı䷽��
		switch (key)
		{
		case 'w':
		case 'W':
			dx = 0, dy = -1;
			break;
		case 'S':
		case 's':
			dx = 0, dy = 1;
			break;
		case 'A':
		case 'a':
			dx = -1, dy = 0;
			break;
		case 'D':
		case 'd':
			dx = 1, dy = 0;
			break;
		}
		//�ж��Ƿ�����������ײ
		for (int i = 1; i < snake.size; ++i) {
			if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
				clear(26, 2, 68, 28);
				gotoXY(26, 2);
				printf("��Ϸ����!!!���յ÷�Ϊ��%d",score);
				exit(0);
			}
		}
		//�ж��Ƿ�Ե�ʳ��
		if (snake.body[0].x == food[0] && snake.body[0].y == food[1]) {
			initFood();         //ˢ��ʳ��λ��
			++snake.size;    //���ȼ�һ
			score += 10;      
		}
		
		lx = snake.body[snake.size - 1].x;      //��ȡ��β����
		ly = snake.body[snake.size - 1].y; 
		//������������
		for (int i = snake.size - 1; i > 0; --i) {
			snake.body[i].x = snake.body[i - 1].x;
			snake.body[i].y = snake.body[i - 1].y;
		}
		//������ͷ����
		snake.body[0].x += dx;
		snake.body[0].y += dy;
		Sleep(MOVE - score);
	}
	clear(26, 2, 68, 28);
	gotoXY(26, 2);
	printf("��Ϸ����!!!���յ÷�Ϊ��%d", score);
	exit(0);
}

void initFood()             //��ʼ��ʳ��
{
	food[0] = rand() % L + 25;
	food[1] = rand() % H;
}

void initSnake()             //��ʼ����
{
	snake.size = 2;
	snake.body[0].x = L / 2 + 21;
	snake.body[0].y = H / 2;
	snake.body[1].x = L / 2 + 20;
	snake.body[1].y = H / 2;
}

void showMap()
{
	gotoXY(lx, ly);
	putchar(' ');          //����ĩβ�ո�

	//��ӡ��
	for (int i = 0; i < snake.size; ++i) {
		if (i == 0) {
			gotoXY(snake.body[i].x, snake.body[i].y);
			putchar('@');
		}
		else {
			gotoXY(snake.body[i].x, snake.body[i].y);
			putchar('*');
		}
	}
	//��ӡʳ��λ��
	gotoXY(food[0], food[1]);
	putchar('+');
	//��ʾ��ǰ�÷�
	gotoXY(96, 3);
	printf("��ǰ�÷֣�%d", score);
	//��ʾ��ǰ�ٶ�
	gotoXY(96, 4);
	printf("�ƶ��ٶȣ�%.1f", (double)MOVE / (double)(MOVE - score) * 100.0);
}
