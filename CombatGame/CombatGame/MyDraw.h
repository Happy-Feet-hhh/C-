#ifndef __MYDRAW_H__
#define __MYDRAW_H__

#include<windows.h>
#include<cstdio>
#include<cstdlib>
#include"Master.h"



namespace MyDraw {
	/*
	*	�ı�������ɫ
	*/
	void setConsoleColor(int x);

	// �ƶ����λ��
	void setCursorPosition(const short left, const short top);

	/*
	*	���ָ���е���ʾ��Ϣ�����������������õĿ���̨��С������ղ���
	*	system("mode con cols=120 lines=30  ");
	*/
	void clearLine(int line);

	/*
	*	��ָ���е�ָ����ʼλ�����ָ����ȵ�����,���������������õĿ���̨��С������ղ���
	*	system("mode con cols=120 lines=30  ");
	*/
	void clearLine(const int line, const int start, const int width);

	/*
	*	���60���հ��ַ����պ�����Ļ��һ�룬���ڲ�����ɫ���ߵ�����Ϣʹ��
	*	system("mode con cols=120 lines=30  ");
	*/
	void writeEmpty();

	/*
	*	��ն�Ӧ��ŵ���һ��ߵ�����Ϣ
	*/
	void clearCharacterInfo(Soldier& player, int i);

	/*
	*	��ʾ�غ���
	*/
	void drawRounds(int round);

	/*
	*	��ʾ����
	*/
	void drawMain(Soldier** A, Soldier** B);

	/*
	*	����ָ����ɫ������������ѡ�еĽ�ɫ
	*/
	void drawCharacter(Soldier* player, int line, int round);

};


#endif