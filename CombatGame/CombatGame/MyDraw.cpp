#include"MyDraw.h"

namespace MyDraw {
	/*
	*	�ı�������ɫ
	*/
	void setConsoleColor(int x) {
		HANDLE h = GetStdHandle(-11);
		SetConsoleTextAttribute(h, x);
	}

	// �ƶ����λ��
	void setCursorPosition(const short left, const short top) {
		static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cp = { left, top };
		SetConsoleCursorPosition(handle, cp);
	}

	/*
	*	���ָ���е���ʾ��Ϣ�����������������õĿ���̨��С������ղ���
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
	*	��ָ���е�ָ����ʼλ�����ָ����ȵ�����,���������������õĿ���̨��С������ղ���
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
	*	���25���հ��ַ������ڲ�����ɫ���ߵ���ʹ�ü��ܵ���Ϣ
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
	*	��ʾ�غ���
	*/
	void drawRounds(int round) {
		setConsoleColor(15);
		setCursorPosition(49, 0);
		std::cout << "��" << round << "�غ�,��ʼ��";
		setCursorPosition(0, 0);
	}

	/*
	*	��ʾ����
	*/
	void drawMain(Soldier** A, Soldier** B) {
		// ���ƾ���A(��ɫ)
		setConsoleColor(4);
		for (int i = 0, line = 3; i < NUMBEROFLEGIONS; ++i, line += 6) {
			setCursorPosition(0, line);
			std::cout << A[i]->getName() << "ְҵ��" << A[i]->getClassName() << "  �ȼ���" << A[i]->getLevel() ;
			setCursorPosition(0, line + 1);
			std::cout << "  HP��(" << A[i]->getHP() << "/" << A[i]->getmaxHP() << ")";
			setCursorPosition(0, line + 2);
			std::cout << "  SP��(" << A[i]->getSP() << "/" << A[i]->getmaxSP() << ")";
			setCursorPosition(0, line + 3);
			std::cout << "  MP��(" << (A[i])->getMP() << "/" << A[i]->getmaxMP() << ")";
			setCursorPosition(0, line + 4);
			std::cout << "  NP��(" << (A[i])->getNP() << "/" << A[i]->getmaxNP() << ")";
		}

		// ���ƾ���B(��ɫ)
		setConsoleColor(10);
		for (int i = 0, line = 3; i < NUMBEROFLEGIONS; ++i, line += 6) {
			setCursorPosition(90, line);
			std::cout << B[i]->getName() << "ְҵ��" << B[i]->getClassName() << "  �ȼ���" << B[i]->getLevel();;
			setCursorPosition(90, line + 1);
			std::cout << "  HP��(" << B[i]->getHP() << "/" << B[i]->getmaxHP() << ")";
			setCursorPosition(90, line + 2);
			std::cout << "  SP��(" << B[i]->getSP() << "/" << B[i]->getmaxSP() << ")";
			setCursorPosition(90, line + 3);
			std::cout << "  MP��(" << (B[i])->getMP() << "/" << B[i]->getmaxMP() << ")";
			setCursorPosition(90, line + 4);
			std::cout << "  NP��(" << (B[i])->getNP() << "/" << B[i]->getmaxNP() << ")";
		}
		setConsoleColor(15);
		setCursorPosition(40, 15);
	}

	/*
	*	����ָ����ɫ������������ѡ�еĽ�ɫ
	*/
	void drawCharacter(Soldier* player, int line, int round) {
		for (int i = 0; i < 4; ++i) {
			// ����A����
			if (!(round % 2)) {
				if (i % 2)
					setConsoleColor(4);
				else
					setConsoleColor(13);

				setCursorPosition(0, line);
				std::cout << player->getName() << "ְҵ��" << player->getClassName() << "  �ȼ���" << player->getLevel();
				setCursorPosition(0, line + 1);
				std::cout << "  HP��(" << player->getHP() << "/" << player->getmaxHP() << ")";
				setCursorPosition(0, line + 2);
				std::cout << "  SP��(" << player->getSP() << "/" << player->getmaxSP() << ")";
				setCursorPosition(0, line + 3);
				std::cout << "  MP��(" << player->getMP() << "/" << player->getmaxMP() << ")";
				setCursorPosition(0, line + 4);
				std::cout << "  NP��(" << player->getNP() << "/" << player->getmaxNP() << ")";
			}
			else {
				if (i % 2)
					setConsoleColor(10);
				else
					setConsoleColor(13);

				setCursorPosition(90, line);
				std::cout << player->getName() << "ְҵ��" << player->getClassName() << "  �ȼ���" << player->getLevel();
				setCursorPosition(90, line + 1);
				std::cout << "  HP��(" << player->getHP() << "/" << player->getmaxHP() << ")";
				setCursorPosition(90, line + 2);
				std::cout << "  SP��(" << player->getSP() << "/" << player->getmaxSP() << ")";
				setCursorPosition(90, line + 3);
				std::cout << "  MP��(" << player->getMP() << "/" << player->getmaxMP() << ")";
				setCursorPosition(90, line + 4);
				std::cout << "  NP��(" << player->getNP() << "/" << player->getmaxNP() << ")";
			}
			Sleep(100);
		}
	}

};