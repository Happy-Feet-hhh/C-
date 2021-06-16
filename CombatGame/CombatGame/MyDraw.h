#ifndef __MYDRAW_H__
#define __MYDRAW_H__

#include<windows.h>
#include<cstdio>
#include<cstdlib>
#include"Master.h"



namespace MyDraw {
	/*
	*	改变字体颜色
	*/
	void setConsoleColor(int x);

	// 移动光标位置
	void setCursorPosition(const short left, const short top);

	/*
	*	清空指定行的显示信息，根据主函数中设置的控制台大小进行清空操作
	*	system("mode con cols=120 lines=30  ");
	*/
	void clearLine(int line);

	/*
	*	在指定行的指定开始位置清空指定宽度的内容,根据主函数中设置的控制台大小进行清空操作
	*	system("mode con cols=120 lines=30  ");
	*/
	void clearLine(const int line, const int start, const int width);

	/*
	*	输出60个空白字符，刚好是屏幕的一半，用于擦除角色或者敌人信息使用
	*	system("mode con cols=120 lines=30  ");
	*/
	void writeEmpty();

	/*
	*	清空对应序号的玩家或者敌人信息
	*/
	void clearCharacterInfo(Soldier& player, int i);

	/*
	*	显示回合数
	*/
	void drawRounds(int round);

	/*
	*	显示军团
	*/
	void drawMain(Soldier** A, Soldier** B);

	/*
	*	绘制指定角色，用于描述被选中的角色
	*/
	void drawCharacter(Soldier* player, int line, int round);

};


#endif