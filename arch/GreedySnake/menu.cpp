#include "menu.h"
#include <stdio.h>

/*
	�˵������������
*/

const int H = 30;         //��Ϸ���ڵĿ�
const int L = 120;           //��Ϸ���ڵĳ�
const char Border = '#';           //�߽����ʽ
char map_Border[H][L];             //�洢��ͼ�߽�


/*
	��ʼ���߿�
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
	��ӡһ���߿�
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
