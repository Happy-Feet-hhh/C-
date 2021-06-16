#include"MyDraw.h"

namespace MyDraw {
	/*
	*	改变字体颜色
	*/
	void setConsoleColor(int x) {
		HANDLE h = GetStdHandle(-11);
		SetConsoleTextAttribute(h, x);
	}

	// 移动光标位置
	void setCursorPosition(const short left, const short top) {
		static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cp = { left, top };
		SetConsoleCursorPosition(handle, cp);
	}

	/*
	*	清空指定行的显示信息，根据主函数中设置的控制台大小进行清空操作
	*	system("mode con cols=120 lines=30  ");
	*/
	void clearLine(int line) {
		setCursorPosition(0, line);
		for (int i = 0; i < 120; ++i) {
			printf(" ");
		}
		setCursorPosition(0, 0);
	}

	/*
	*	在指定行的指定开始位置清空指定宽度的内容,根据主函数中设置的控制台大小进行清空操作
	*	system("mode con cols=120 lines=30  ");
	*/
	void clearLine(const int line, const int start, const int width) {
		setCursorPosition(start, line);
		for (int i = 0; i < width; i++) {
			printf(" ");
		}
		setCursorPosition(0, 0);
	}

	/*
	*	输出25个空白字符，用于擦除角色或者敌人使用技能的信息
	*	system("mode con cols=120 lines=30  ");
	*/
	void writeEmpty() {
		for (int i = 15; i < 25; i++) {
			setCursorPosition(40, i);
			printf("                                            ");
		}
		setCursorPosition(40, 15);
	}

	/*
	*	显示回合数
	*/
	void drawRounds(int round) {
		setConsoleColor(15);
		setCursorPosition(49, 0);
		std::cout << "第" << round << "回合,开始！";
		setCursorPosition(0, 0);
	}

	/*
	*	显示军团
	*/
	void drawMain(Soldier** A, Soldier** B) {
		// 绘制军团A(红色)
		setConsoleColor(4);
		for (int i = 0, line = 3; i < NUMBEROFLEGIONS; ++i, line += 6) {
			setCursorPosition(0, line);
			std::cout << A[i]->getName() << "职业：" << A[i]->getClassName() << "  等级：" << A[i]->getLevel() ;
			setCursorPosition(0, line + 1);
			std::cout << "  HP：(" << A[i]->getHP() << "/" << A[i]->getmaxHP() << ")";
			setCursorPosition(0, line + 2);
			std::cout << "  SP：(" << A[i]->getSP() << "/" << A[i]->getmaxSP() << ")";
			setCursorPosition(0, line + 3);
			std::cout << "  MP：(" << (A[i])->getMP() << "/" << A[i]->getmaxMP() << ")";
			setCursorPosition(0, line + 4);
			std::cout << "  NP：(" << (A[i])->getNP() << "/" << A[i]->getmaxNP() << ")";
		}

		// 绘制军团B(绿色)
		setConsoleColor(10);
		for (int i = 0, line = 3; i < NUMBEROFLEGIONS; ++i, line += 6) {
			setCursorPosition(90, line);
			std::cout << B[i]->getName() << "职业：" << B[i]->getClassName() << "  等级：" << B[i]->getLevel();;
			setCursorPosition(90, line + 1);
			std::cout << "  HP：(" << B[i]->getHP() << "/" << B[i]->getmaxHP() << ")";
			setCursorPosition(90, line + 2);
			std::cout << "  SP：(" << B[i]->getSP() << "/" << B[i]->getmaxSP() << ")";
			setCursorPosition(90, line + 3);
			std::cout << "  MP：(" << (B[i])->getMP() << "/" << B[i]->getmaxMP() << ")";
			setCursorPosition(90, line + 4);
			std::cout << "  NP：(" << (B[i])->getNP() << "/" << B[i]->getmaxNP() << ")";
		}
		setConsoleColor(15);
		setCursorPosition(40, 15);
	}

	/*
	*	绘制指定角色，用于描述被选中的角色
	*/
	void drawCharacter(Soldier* player, int line, int round) {
		for (int i = 0; i < 4; ++i) {
			// 绘制A军团
			if (!(round % 2)) {
				if (i % 2)
					setConsoleColor(4);
				else
					setConsoleColor(13);

				setCursorPosition(0, line);
				std::cout << player->getName() << "职业：" << player->getClassName() << "  等级：" << player->getLevel();
				setCursorPosition(0, line + 1);
				std::cout << "  HP：(" << player->getHP() << "/" << player->getmaxHP() << ")";
				setCursorPosition(0, line + 2);
				std::cout << "  SP：(" << player->getSP() << "/" << player->getmaxSP() << ")";
				setCursorPosition(0, line + 3);
				std::cout << "  MP：(" << player->getMP() << "/" << player->getmaxMP() << ")";
				setCursorPosition(0, line + 4);
				std::cout << "  NP：(" << player->getNP() << "/" << player->getmaxNP() << ")";
			}
			else {
				if (i % 2)
					setConsoleColor(10);
				else
					setConsoleColor(13);

				setCursorPosition(90, line);
				std::cout << player->getName() << "职业：" << player->getClassName() << "  等级：" << player->getLevel();
				setCursorPosition(90, line + 1);
				std::cout << "  HP：(" << player->getHP() << "/" << player->getmaxHP() << ")";
				setCursorPosition(90, line + 2);
				std::cout << "  SP：(" << player->getSP() << "/" << player->getmaxSP() << ")";
				setCursorPosition(90, line + 3);
				std::cout << "  MP：(" << player->getMP() << "/" << player->getmaxMP() << ")";
				setCursorPosition(90, line + 4);
				std::cout << "  NP：(" << player->getNP() << "/" << player->getmaxNP() << ")";
			}
			Sleep(100);
		}
	}

};