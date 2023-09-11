#include "menu.h"
#include <stdio.h>

/*
	菜单中所需的数据
*/

const int H = 30;         //游戏窗口的宽
const int L = 120;           //游戏窗口的长
const char Border = '#';           //边界的样式
char map_Border[H][L];             //存储地图边界


/*
	初始化边框
*/
static void initBorder()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < L; ++j) {
			if (i == 0 || i == H - 1 || j == 0 || j == L - 1) {
				map_Border[i][j] = Border;
			}
			else {
				map_Border[i][j] = ' ';
			}
		}
	}
}

/*
	打印一个边框
*/
void printBorder()
{
	initBorder();
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < L; ++j) {
			printf("%c",map_Border[i][j]);
		}
		printf("\n");
	}
}
