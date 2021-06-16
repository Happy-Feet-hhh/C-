#include"WarSystem.h"
#include<windows.h>
#include"MyDraw.h"

// 判断是否失败
bool WarSystem::isDefeat(Soldier** legions) {
	for (int i = 0; i < NUMBEROFLEGIONS; ++i) {
		if (legions[i]->getHP() > 0)
			return false;
	}
	return true;
}

// 开始战斗
void WarSystem::startWar(Soldier** legionsA, Soldier** legionsB) {
	int round = 1; // 控制回合数，决定哪个军团出击记
	do {
		MyDraw::drawRounds(round);
		MyDraw::drawMain(legionsA, legionsB);
		if (round++ % 2)
			startRound(legionsA, legionsB, round);
		else
			startRound(legionsB, legionsA, round);
		Sleep(2000);
		system("cls");
	} while (!isDefeat(legionsA) && !isDefeat(legionsB));
	if (isDefeat(legionsA))
		std::cout << "B军团胜利" << std::endl;
	else
		std::cout << "A军团胜利" << std::endl;
}

// 开始回合
void WarSystem::startRound(Soldier** legionsA, Soldier** legionsB, int round) {
	for (int i = 0, line = 3; i < NUMBEROFLEGIONS; ++i, line += 6) {
		if (legionsA[i]->getHP() > 0) {
			legionsA[i]->makeDecision(legionsB);
			MyDraw::drawCharacter(legionsA[i], line, round);
			Sleep(2000);
			MyDraw::writeEmpty();
		}
	}
}