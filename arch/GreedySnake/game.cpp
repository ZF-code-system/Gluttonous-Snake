#include "game.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include<time.h>
#include<Windows.h>

int gameTime = 0;
int score = 0;       //游戏得分

int dx = 0;         //偏移坐标
int dy = 0;   

int lx = 0;          //蛇尾坐标
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
	游戏界面
*/

void gameView()
{
	gameTime = 0;         //游戏用时
	char key = 'D';       //初始化当前方向为右           

	while (snake.body[0].x >= 25 && snake.body[0].x < L + 25 && snake.body[0].y >= 0 && snake.body[0].y < H) {
		showMap();

		while (_kbhit()) {//_kbhit()用于判断控制台是否有输入，有输入则接收
			key = _getch();//用于无显示接收键盘内容
		}
		//改变方向
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
		//判断是否与自身发生碰撞
		for (int i = 1; i < snake.size; ++i) {
			if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
				clear(26, 2, 68, 28);
				gotoXY(26, 2);
				printf("游戏结束!!!最终得分为：%d",score);
				exit(0);
			}
		}
		//判断是否吃的食物
		if (snake.body[0].x == food[0] && snake.body[0].y == food[1]) {
			initFood();         //刷新食物位置
			++snake.size;    //长度加一
			score += 10;      
		}
		
		lx = snake.body[snake.size - 1].x;      //获取蛇尾坐标
		ly = snake.body[snake.size - 1].y; 
		//更新蛇身坐标
		for (int i = snake.size - 1; i > 0; --i) {
			snake.body[i].x = snake.body[i - 1].x;
			snake.body[i].y = snake.body[i - 1].y;
		}
		//更新蛇头坐标
		snake.body[0].x += dx;
		snake.body[0].y += dy;
		Sleep(MOVE - score);
	}
	clear(26, 2, 68, 28);
	gotoXY(26, 2);
	printf("游戏结束!!!最终得分为：%d", score);
	exit(0);
}

void initFood()             //初始化食物
{
	food[0] = rand() % L + 25;
	food[1] = rand() % H;
}

void initSnake()             //初始化蛇
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
	putchar(' ');          //更新末尾空格

	//打印蛇
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
	//打印食物位置
	gotoXY(food[0], food[1]);
	putchar('+');
	//显示当前得分
	gotoXY(96, 3);
	printf("当前得分：%d", score);
	//显示当前速度
	gotoXY(96, 4);
	printf("移动速度：%.1f", (double)MOVE / (double)(MOVE - score) * 100.0);
}
