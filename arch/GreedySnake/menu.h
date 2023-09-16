#pragma once

extern char key;           //用户输入
//extern int userChoose;     //用户当前选择开始游戏 

/*
	菜单中所包含的函数
*/

void printBorder();        //打印游戏边界

void printMenu();            //打印游戏菜单界面

void gotoXY(int x,int y);     //将光标x,y传到制定位置

void setPrintcolor(int color);   //设置控制台文本颜色

void userInput(char input,int *userChoose);               //获取用户在键盘上的输入

void clear(int x, int y, int w, int h);  //清理制定区域从(x,y)到(x+w,y+h)
