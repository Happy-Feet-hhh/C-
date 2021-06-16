#ifndef __WARSYSTEM_H__
#define __WARSYSTEM_H__
#include"Master.h"

class WarSystem {
public:
	// 构造函数实现两军团的初始化
	WarSystem() : _PGroupA(new Soldier* [NUMBEROFLEGIONS]), _pGroupB(new Soldier* [NUMBEROFLEGIONS]) {
		for (int i = 0; i < NUMBEROFLEGIONS; ++i) {
			if (i < 2) {
				_PGroupA[i] = new Soldier();
				_pGroupB[i] = new Soldier();
			}
			else if (i < 3) {
				_PGroupA[i] = new Wizard();
				_pGroupB[i] = new Wizard();
			}
			else {
				_PGroupA[i] = new Master();
				_pGroupB[i] = new Master();
			}
		}
	}
	// 判断是否失败的函数
	bool isDefeat(Soldier** legions);
	void startWar(Soldier** legionsA, Soldier** legionsB);
//private:
	Soldier** _PGroupA;
	Soldier** _pGroupB;

	void startRound(Soldier** legionsA, Soldier** legionsB, int round);
};


#endif