#pragma once

extern char key;           //�û�����
//extern int userChoose;     //�û���ǰѡ��ʼ��Ϸ 

/*
	�˵����������ĺ���
*/

void printBorder();        //��ӡ��Ϸ�߽�

void printMenu();            //��ӡ��Ϸ�˵�����

void gotoXY(int x,int y);     //�����x,y�����ƶ�λ��

void setPrintcolor(int color);   //���ÿ���̨�ı���ɫ

void userInput(char input,int *userChoose);               //��ȡ�û��ڼ����ϵ�����

void clear(int x, int y, int w, int h);  //�����ƶ������(x,y)��(x+w,y+h)
