#include<Windows.h>
#include"menu.h"
#include"game.h"
#include <time.h>
using namespace std;

int main() {
	//清除控制台光标
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	srand((unsigned)time(NULL));

	initFood();
	initSnake();

	printMenu();
	system("pause");
	return 0;
}